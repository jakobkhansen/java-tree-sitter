package ai.serenade.treesitter;

public class TSQueryCursor {
    public long pointer;

    public TSQueryCursor() {
        this.pointer = TreeSitter.tsQueryCursorNew();
    }

    public void execQuery(TSQuery query, Node node) {
        TreeSitter.tsQueryCursorExec(pointer, query.pointer, node);
    }

    public TSQueryMatch nextMatch() {
        return TreeSitter.tsQueryCursorNextMatch(pointer);
    }
}
