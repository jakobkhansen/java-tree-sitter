package ai.serenade.treesitter;

public class TSQueryMatch {
    private int id;
    private int pattern_index;
    TSQueryCapture[] captures;

    public TSQueryMatch(int id, int pattern_index, TSQueryCapture[] captures) {
        this.id = id;
        this.pattern_index = pattern_index;
        this.captures = captures;
    }

    public int getId() {
        return id;
    }

    public int getPatternIndex() {
        return pattern_index;
    }

    public TSQueryCapture[] getCaptures() {
        return captures;
    }
}
