package ai.serenade.treesitter;

/**
 * InputEdit
 */
public class TSInputEdit {

    int startByte;
    int oldEndByte;
    int newEndByte;
    TSPoint old_end_point;
    TSPoint new_end_point;

    public TSInputEdit(
        int startByte,
        int oldEndByte,
        int newEndByte,
        TSPoint old_end_point,
        TSPoint new_end_point
    ) {
        this.startByte = startByte;
        this.oldEndByte = oldEndByte;
        this.newEndByte = newEndByte;
        this.old_end_point = old_end_point;
        this.new_end_point = new_end_point;
    }
}
