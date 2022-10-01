package ai.serenade.treesitter;

public class TSQueryCapture {
    public Node node;
    public int index;

    public TSQueryCapture(Node node, int index) {
        this.node = node;
        this.index = index;
    }
}
