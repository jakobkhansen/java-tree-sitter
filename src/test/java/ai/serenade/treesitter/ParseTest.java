package ai.serenade.treesitter;

import static org.junit.jupiter.api.Assertions.assertEquals;

import java.io.UnsupportedEncodingException;
import java.nio.charset.StandardCharsets;

import org.junit.jupiter.api.Test;

public class ParseTest extends TestBase {

    @Test
    void testParsesRangeCorrectly() throws UnsupportedEncodingException {
        // String source = "class Hello {" + System.lineSeparator() + "int x = 3;" +
        // System.lineSeparator()
        // + "float y = 3.0;" + System.lineSeparator() + "hello(y);" +
        // System.lineSeparator() + "}";
        String source = "class Hello{\nint x = 3;\n\n\n\n\n\n\n\nfloat y = 3.0;\nhello(y);\n}";
        try (Parser parser = new Parser()) {
            parser.setLanguage(Languages.python());
            try (Tree tree = parser.parseString(source)) {
                Node root = tree.getRootNode();
                traverse(root);
            }
        }
    }

    public static void traverse(Node node) {
        System.out.println(node.getType());
        System.out.println(print(node.toRange()));
        System.out.println();

        for (int i = 0; i < node.getChildCount(); i++) {
            traverse(node.getChild(i));
        }
    }

    public static String print(TSPoint point) {
        String out = "TSPoint(";
        out += point.row + ", " + point.column + ")";

        return out;
    }

    public static String print(TSRange range) {
        if (range == null) {
            return "TSRange(null)";
        }
        String out = "TSRange(";
        out += "\nstart_byte: " + range.getStartByte();
        out += "\nend_byte: " + range.getEndByte();
        out += "\nstart_point: " + print(range.getStartPoint());
        out += "\nend_point: " + print(range.getEndPoint());

        return out + ")";
    }

}
