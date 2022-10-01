package ai.serenade.treesitter;

import static org.junit.jupiter.api.Assertions.assertNotEquals;

import java.io.UnsupportedEncodingException;

import org.junit.jupiter.api.Test;

public class TSQueryCursorTest extends TestBase {

    @Test
    void testCreateQueryCursor() throws UnsupportedEncodingException {
        TSQueryCursor cursor = new TSQueryCursor();
        assertNotEquals(0, cursor.pointer, "Pointer is not null");
    }

    @Test
    void testExecSimpleQuery() throws UnsupportedEncodingException {
        try (Parser parser = new Parser()) {
            parser.setLanguage(Languages.java());
            Tree tree = parser.parseString("class Hello {}");
            TSQuery query = new TSQuery(Languages.java(), "(class_body)");

            TSQueryCursor cursor = new TSQueryCursor();

            cursor.execQuery(query, tree.getRootNode());
        }
    }

}
