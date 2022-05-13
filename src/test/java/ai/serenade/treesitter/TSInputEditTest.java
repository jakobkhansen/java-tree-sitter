package ai.serenade.treesitter;

import static org.junit.jupiter.api.Assertions.assertEquals;

import java.io.UnsupportedEncodingException;

import org.junit.jupiter.api.Test;

/**
 * TSInputEditTest
 */
public class TSInputEditTest extends TestBase {

    @Test
    void testInputEdit() throws UnsupportedEncodingException {
        try (Parser parser = new Parser()) {
            parser.setLanguage(Languages.java());

            // Parse code
            Tree tree = parser.parseString(
                "class Hello {\npublic void hello() {}}"
            );


            // Empty edit
            Node editedNode = tree.getRootNode().getChild(0).getChild(2).getChild(1).getChild(4);
            TSPoint newEndPoint = new TSPoint(editedNode.getEndPoint().row, editedNode.getEndPoint().column);
            TSInputEdit edit = new TSInputEdit(
                editedNode.getStartByte(),
                editedNode.getEndByte(),
                editedNode.getEndByte(),
                editedNode.getStartPoint(),
                editedNode.getEndPoint(),
                newEndPoint
            );

            String oldSExp = tree.getRootNode().getNodeString();

            tree.edit(edit);

            tree = parser.parseString(tree, "class Hello {\npublic void hello() {\nint x = 3; }}");

            String newSExp = tree.getRootNode().getNodeString();
            assertEquals(oldSExp, newSExp);
        }
    }
}
