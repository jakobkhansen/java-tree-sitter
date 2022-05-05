package ai.serenade.treesitter;

/**
 * App
 */
public class App {
    static {
        System.load("/home/jakob/Documents/Dev/java-tree-sitter/parser.so");
    }

    public static void main(String[] args) {
        try (Parser parser = new Parser()) {
            parser.setLanguage(Languages.java());
            Tree tree = parser.parseString(
                "class Hello  {\npublic void hello() {}}"
            );
            System.out.println(tree.getRootNode().getNodeString());
            // System.out.println(
            //     tree.getRootNode().getChild(0).getChild(1).getChildCount()
            // );
            // System.out.println(
            //     tree.getRootNode().getChild(0).getChildCount()
            // );
            // System.out.println(
            //     tree.getRootNode().getChild(0).getChild(2).getNodeString()
            // );
            // System.out.println(
            //     tree.getRootNode().getChild(0).getChild(2).getStartPoint()
            // );
            // System.out.println(
            //     tree.getRootNode().getChild(0).getChild(2).getEndPoint()
            // );
            // System.out.println(
            //     tree.getRootNode().getChild(0).getChild(2).getStartByte()
            // );
            // System.out.println(
            //     tree.getRootNode().getChild(0).getChild(2).getEndByte()
            // );
            System.out.println(tree.getRootNode().getChild(0).getChild(2).getChild(1).getChild(4).getNodeString());
            Node editedNode = tree.getRootNode().getChild(0).getChild(2).getChild(1).getChild(4);
            TSPoint newEndPoint = new TSPoint(editedNode.getEndPoint().row, editedNode.getEndPoint().column);
            newEndPoint.column += 9;
            TSInputEdit edit = new TSInputEdit(
                editedNode.getStartByte(),
                editedNode.getEndByte(),
                editedNode.getEndByte() + 9,
                editedNode.getStartPoint(),
                editedNode.getEndPoint(),
                newEndPoint
            );

            tree.edit(edit);


            tree = parser.parseString(tree, "class Hello  {\npublic void hello() {int x = 2; }}");
            System.out.println(tree.getRootNode().getNodeString());
        } catch (Exception e) {} finally {}
    }
}
