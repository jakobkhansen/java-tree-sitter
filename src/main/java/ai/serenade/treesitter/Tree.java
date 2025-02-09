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
        TreeSitter.treeEdit(
                pointer,
                edit);
    }

    public TSRange[] getChangedRanges(Tree old_tree) {
        return TreeSitter.treeGetChangedRanges(old_tree.getPointer(), pointer);
    }

    public long getPointer() {
        return pointer;
    }

}
