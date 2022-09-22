package ai.serenade.treesitter;

public class TSRange {
    public TSPoint start_point;
    public TSPoint end_point;

    public int start_byte;
    public int end_byte;

    public TSRange(TSPoint start_point, TSPoint end_point, int start_byte, int end_byte) {
        this.start_point = start_point;
        this.end_point = end_point;
        this.start_byte = start_byte;
        this.end_byte = end_byte;
    }
}
