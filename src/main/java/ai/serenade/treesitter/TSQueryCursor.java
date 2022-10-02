package ai.serenade.treesitter;

public class TSQueryCursor {
    long pointer;

    public TSQueryCursor() {
        this.pointer = TreeSitter.tsQueryCursorNew();
    }

    public void execQuery(TSQuery query, Node node) {
        TreeSitter.tsQueryCursorExec(pointer, query.getPointer(), node);
    }

    public TSQueryMatch nextMatch() {
        return TreeSitter.tsQueryCursorNextMatch(pointer);
    }

    public long getPointer() {
        return pointer;
    }
}
