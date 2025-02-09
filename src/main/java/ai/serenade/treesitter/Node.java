package ai.serenade.treesitter;

public class Node {
    private int context0;
    private int context1;
    private int context2;
    private int context3;
    private long id;
    private long tree;

    public Node() {
    }

    public Node getChild(int child) {
        return TreeSitter.nodeChild(this, child);
    }

    public Node getParent() {
        return TreeSitter.nodeParent(this);
    }

    public int getChildCount() {
        return TreeSitter.nodeChildCount(this);
    }

    public int getEndByte() {
        return TreeSitter.nodeEndByte(this);
    }

    public String getNodeString() {
        return TreeSitter.nodeString(this);
    }

    public int getStartByte() {
        return TreeSitter.nodeStartByte(this);
    }

    public TSPoint getStartPoint() {
        return TreeSitter.nodeStartPoint(this);
    }

    public TSPoint getEndPoint() {
        return TreeSitter.nodeEndPoint(this);
    }

    public String getType() {
        return TreeSitter.nodeType(this);
    }

    public boolean isNamed() {
        return TreeSitter.nodeIsNamed(this);
    }

    public boolean isExtra() {
        return TreeSitter.nodeIsExtra(this);
    }

    public TSRange toRange() {
        return new TSRange(getStartPoint(), getEndPoint(), getStartByte(), getEndByte());
    }

    public TreeCursor walk() {
        return new TreeCursor(TreeSitter.treeCursorNew(this));
    }
}
