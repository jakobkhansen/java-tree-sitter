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
        String source = "class Hello{\nint x = 3;\n\n\n\n\n\n\n\nfloat y = 3.0;\nhello(\"y\");\n}";
        try (Parser parser = new Parser()) {
            parser.setLanguage(Languages.java());
            try (Tree tree = parser.parseString(source)) {
                Node root = tree.getRootNode();
            }
        }
    }
}
