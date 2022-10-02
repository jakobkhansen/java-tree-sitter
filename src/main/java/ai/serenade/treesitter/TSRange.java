package ai.serenade.treesitter;

public class TSRange {
    private TSPoint start_point;
    private TSPoint end_point;

    private int start_byte;
    private int end_byte;

    public TSRange(TSPoint start_point, TSPoint end_point, int start_byte, int end_byte) {
        this.start_point = start_point;
        this.end_point = end_point;
        this.start_byte = start_byte;
        this.end_byte = end_byte;
    }

    public TSPoint getStartPoint() {
        return start_point;
    }

    public TSPoint getEndPoint() {
        return end_point;
    }

    public int getStartByte() {
        return start_byte;
    }

    public int getEndByte() {
        return end_byte;
    }
}
