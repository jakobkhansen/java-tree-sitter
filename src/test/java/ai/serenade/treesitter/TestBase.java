package ai.serenade.treesitter;


import org.junit.platform.commons.logging.Logger;
import org.junit.platform.commons.logging.LoggerFactory;

public class TestBase {
  static {
    System.load(System.getenv("JAVA_TREE_SITTER"));
  }
}
