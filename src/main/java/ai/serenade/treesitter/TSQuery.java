package ai.serenade.treesitter;

/**
 * TSQuery
 */
public class TSQuery {
    private long pointer;

    public TSQuery(long language, String source) {
        this.pointer = TreeSitter.tsQueryNew(language, source);
    }

    public long getPointer() {
        return pointer;
    }
}
