package ai.serenade.treesitter;

import static org.junit.jupiter.api.Assertions.assertEquals;

import java.io.UnsupportedEncodingException;
import org.junit.jupiter.api.Test;

public class TSQueryTest extends TestBase {

    @Test
    void testQuery() throws UnsupportedEncodingException {
        try (Parser parser = new Parser()) {
            parser.setLanguage(Languages.java());
            try (Tree tree = parser.parseString("class Hello {}")) {
                TSQuery query = new TSQuery(Languages.java(), "(class_declaration)");
            }
        }
    }
}
