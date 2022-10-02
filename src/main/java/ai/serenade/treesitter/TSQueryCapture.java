package ai.serenade.treesitter;

public class TSQueryCapture {
    Node node;
    int index;

    public TSQueryCapture(Node node, int index) {
        this.node = node;
        this.index = index;
    }

    public Node getNode() {
        return node;
    }

    public int getIndex() {
        return index;
    }
}
