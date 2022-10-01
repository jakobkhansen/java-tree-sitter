package ai.serenade.treesitter;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotEquals;

import java.io.UnsupportedEncodingException;
import org.junit.jupiter.api.Test;

public class TSQueryTest extends TestBase {

    @Test
    void testQuery() throws UnsupportedEncodingException {
        TSQuery query = new TSQuery(Languages.java(), "(class_declaration)");

        assertNotEquals(query.pointer, 0, "Pointer is not null");

    }

    @Test
    void testInvalidQuery() throws UnsupportedEncodingException {
        TSQuery query = new TSQuery(Languages.java(), "(class_declaration");

        assertEquals(query.pointer, 0, "Pointer is null");
    }
}
