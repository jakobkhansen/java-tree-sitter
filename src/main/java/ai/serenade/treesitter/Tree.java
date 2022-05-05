package ai.serenade.treesitter;

public class Tree implements AutoCloseable {

    private long pointer;

    Tree(long pointer) {
        this.pointer = pointer;
    }

    @Override
    public void close() {
        TreeSitter.treeDelete(pointer);
    }

    public Node getRootNode() {
        return TreeSitter.treeRootNode(pointer);
    }

    public void edit(TSInputEdit edit) {
        int start_byte = edit.startByte;
        int old_end_byte = edit.oldEndByte;
        int new_end_byte = edit.newEndByte;
        int old_end_point_row = edit.old_end_point.row;
        int old_end_point_col = edit.old_end_point.column;
        int new_end_point_row = edit.new_end_point.row;
        int new_end_point_col = edit.new_end_point.column;

        TreeSitter.treeEdit(
            pointer,
            start_byte,
            old_end_byte,
            new_end_byte,
            old_end_point_row,
            old_end_point_col,
            new_end_point_row,
            new_end_point_col
        );
    }
}
