package ai.serenade.treesitter;

/**
 * TSQuery
 */
public class TSQuery {
    public long pointer;

    public TSQuery(long language, String source) {
        this.pointer = TreeSitter.tsQueryNew(language, source);
    }
}
