package ai.serenade.treesitter;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotEquals;
import static org.junit.jupiter.api.Assertions.assertNull;

import java.io.UnsupportedEncodingException;

import org.junit.jupiter.api.Test;

import ai.serenade.treesitter.utils.Printer;

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
            TSQuery query = new TSQuery(Languages.java(), "(class_body) @test");

            TSQueryCursor cursor = new TSQueryCursor();

            cursor.execQuery(query, tree.getRootNode());
            int numMatches = 0;
            while (cursor.nextMatch() != null) {
                numMatches++;
            }

            assertEquals(1, numMatches, "Finds one match");

        }
    }

    @Test
    void testExecNoResultQuery() throws UnsupportedEncodingException {
        try (Parser parser = new Parser()) {
            parser.setLanguage(Languages.java());
            Tree tree = parser.parseString("class Hello {}");
            TSQuery query = new TSQuery(Languages.java(), "(method_declaration) @method");

            TSQueryCursor cursor = new TSQueryCursor();

            cursor.execQuery(query, tree.getRootNode());

            assertNull(cursor.nextMatch());

        }
    }

}
