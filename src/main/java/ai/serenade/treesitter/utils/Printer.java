package ai.serenade.treesitter.utils;

import ai.serenade.treesitter.Node;
import ai.serenade.treesitter.TSInputEdit;
import ai.serenade.treesitter.TSPoint;
import ai.serenade.treesitter.TSRange;

public class Printer {

    public static String print(TSInputEdit edit) {
        String out = "TSInputEdit(\n";
        out += "\nstart_byte: " + edit.startByte;
        out += "\nold_end_byte: " + edit.oldEndByte;
        out += "\nnew_end_byte: " + edit.newEndByte;
        out += "\nstart_point" + print(edit.start_point);
        out += "\nold_end_point" + print(edit.old_end_point);
        out += "\nnew_end_point" + print(edit.new_end_point);

        return out;
    }

    public static String print(TSRange range) {
        String out = "TSInputEdit(\n";
        out += "\nstart_byte: " + range.start_byte;
        out += "\nend_byte: " + range.end_byte;
        out += "\nstart_point" + print(range.start_point);
        out += "\nend_point" + print(range.end_point);

        return out;
    }

    public static String print(TSPoint point) {
        String out = "TSPoint(";
        out += point.row + ", " + point.column + ")";

        return out;
    }

    public static String print(Node node) {
        String out = "Node(";
        out += "\nstart_byte: " + node.getStartByte();
        out += "\nend_byte: " + node.getEndByte();
        out += "\nstart_point: " + Printer.print(node.getStartPoint());
        out += "\nend_point: " + Printer.print(node.getEndPoint());

        return out;
    }
}
