package ai.serenade.treesitter;

/**
 * App
 */
public class App {
    static {
        System.load("/home/jakob/Documents/Dev/java-tree-sitter/parser.so");
    }

    public static void main(String[] args) {
        String hello = "Hello";
        System.out.println(hello);

        try (Parser parser = new Parser()) {
            parser.setLanguage(Languages.java());
            Tree tree = parser.parseString("class Hello {\npublic void hello() {}}");
            System.out.println(tree.getRootNode().getNodeString());
            System.out.println(tree.getRootNode().getChild(0).getChild(2).getNodeString());
            TSPoint point1 = new TSPoint(0, 0);
            TSPoint point2 = new TSPoint(1, 1);
            // TSInputEdit edit = new TSInputEdit(5, 0, 1, point1, point2);
            // tree.edit(edit);

        } catch (Exception e) {

        } finally {

        }
    }
}
