package ai.serenade.treesitter;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotEquals;
import static org.junit.jupiter.api.Assertions.assertNull;

import java.io.UnsupportedEncodingException;
import org.junit.jupiter.api.Test;

import ai.serenade.treesitter.utils.Printer;

public class NodeTraversalTest extends TestBase {

    @Test
    void testTraversal() throws UnsupportedEncodingException {
        try (Parser parser = new Parser()) {
            parser.setLanguage(Languages.java());
            try (Tree tree = parser.parseString("class Hello {}")) {
                Node root = tree.getRootNode();
                Node child = root.getChild(0);
                Node parent = child.getParent();
                assertEquals(root.getType(), parent.getType());

                Node nop = root.getParent();
                assertNull(nop);
            }
        }
    }
}
