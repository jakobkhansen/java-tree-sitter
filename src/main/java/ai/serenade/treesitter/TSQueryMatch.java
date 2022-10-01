package ai.serenade.treesitter;

public class TSQueryMatch {
    int id;
    int pattern_index;
    TSQueryCapture[] captures;

    public TSQueryMatch(int id, int pattern_index, TSQueryCapture[] captures) {
        this.id = id;
        this.pattern_index = pattern_index;
        this.captures = captures;
    }

}
