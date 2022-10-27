package ai.serenade.treesitter;

import static org.junit.jupiter.api.Assertions.assertEquals;

import java.io.UnsupportedEncodingException;
import org.junit.jupiter.api.Test;

public class TreeCursorTest extends TestBase {

    @Test
    void testWalk() throws UnsupportedEncodingException {
        try (Parser parser = new Parser()) {
            parser.setLanguage(Languages.java());
            try (Tree tree = parser.parseString("class Hello() {}")) {
                try (TreeCursor cursor = tree.getRootNode().walk()) {

                    assertEquals("program", cursor.getCurrentTreeCursorNode().getType());
                    assertEquals("program", cursor.getCurrentNode().getType());
                    assertEquals(true, cursor.gotoFirstChild());
                    assertEquals(true, cursor.gotoParent());
                    assertEquals(false, cursor.gotoParent());
                }
            }
        }
    }
}
