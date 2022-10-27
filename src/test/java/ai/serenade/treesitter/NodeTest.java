package ai.serenade.treesitter;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotEquals;

import java.io.UnsupportedEncodingException;
import org.junit.jupiter.api.Test;

import ai.serenade.treesitter.utils.Printer;

public class NodeTest extends TestBase {

    @Test
    void testGetChildren() throws UnsupportedEncodingException {
        try (Parser parser = new Parser()) {
            parser.setLanguage(Languages.java());
            try (Tree tree = parser.parseString("class Hello {\n}")) {
                Node root = tree.getRootNode();
                assertEquals(1, root.getChildCount());
                assertEquals(
                        root.getNodeString(),
                        "(program (class_declaration name: (identifier) body: (class_body)))");
            }
        }
    }

    @Test
    void testAttributes() throws UnsupportedEncodingException {
        try (Parser parser = new Parser()) {
            parser.setLanguage(Languages.java());
            try (Tree tree = parser.parseString("class Hello {\n}")) {
                Node root = tree.getRootNode();
                assertEquals(false, root.isExtra(), "Root node should not be extra");
                assertEquals(true, root.isNamed(), "Root node should be named");
                assertEquals(1, root.getEndPoint().column, "Final row should only be one wide");

            }
        }
    }
}
