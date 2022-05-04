package ai.serenade.treesitter;

/**
 * InputEdit
 */
public class InputEdit {
    int startByte;
    int oldEndByte;
    int newEndByte;
    public InputEdit(int startByte, int oldEndByte, int newEndByte) {
        this.startByte = startByte;
        this.oldEndByte = oldEndByte;
        this.newEndByte = newEndByte;
    }
}
