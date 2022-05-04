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
            Tree tree = parser.parseString("class Hello {}");
            System.out.println(tree.getRootNode().getNodeString());
            tree.edit();

        } catch (Exception e) {

        } finally {

        }
    }
}
