/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class ai_serenade_treesitter_TreeSitter */

#ifndef _Included_ai_serenade_treesitter_TreeSitter
#define _Included_ai_serenade_treesitter_TreeSitter
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     ai_serenade_treesitter_TreeSitter
 * Method:    nodeChild
 * Signature: (Lai/serenade/treesitter/Node;I)Lai/serenade/treesitter/Node;
 */
JNIEXPORT jobject JNICALL Java_ai_serenade_treesitter_TreeSitter_nodeChild
  (JNIEnv *, jclass, jobject, jint);

/*
 * Class:     ai_serenade_treesitter_TreeSitter
 * Method:    nodeChildCount
 * Signature: (Lai/serenade/treesitter/Node;)I
 */
JNIEXPORT jint JNICALL Java_ai_serenade_treesitter_TreeSitter_nodeChildCount
  (JNIEnv *, jclass, jobject);

/*
 * Class:     ai_serenade_treesitter_TreeSitter
 * Method:    nodeEndByte
 * Signature: (Lai/serenade/treesitter/Node;)I
 */
JNIEXPORT jint JNICALL Java_ai_serenade_treesitter_TreeSitter_nodeEndByte
  (JNIEnv *, jclass, jobject);

/*
 * Class:     ai_serenade_treesitter_TreeSitter
 * Method:    nodeStartByte
 * Signature: (Lai/serenade/treesitter/Node;)I
 */
JNIEXPORT jint JNICALL Java_ai_serenade_treesitter_TreeSitter_nodeStartByte
  (JNIEnv *, jclass, jobject);

/*
 * Class:     ai_serenade_treesitter_TreeSitter
 * Method:    nodeString
 * Signature: (Lai/serenade/treesitter/Node;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_ai_serenade_treesitter_TreeSitter_nodeString
  (JNIEnv *, jclass, jobject);

/*
 * Class:     ai_serenade_treesitter_TreeSitter
 * Method:    nodeType
 * Signature: (Lai/serenade/treesitter/Node;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_ai_serenade_treesitter_TreeSitter_nodeType
  (JNIEnv *, jclass, jobject);

/*
 * Class:     ai_serenade_treesitter_TreeSitter
 * Method:    parserNew
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_ai_serenade_treesitter_TreeSitter_parserNew
  (JNIEnv *, jclass);

/*
 * Class:     ai_serenade_treesitter_TreeSitter
 * Method:    parserDelete
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_ai_serenade_treesitter_TreeSitter_parserDelete
  (JNIEnv *, jclass, jlong);

/*
 * Class:     ai_serenade_treesitter_TreeSitter
 * Method:    parserSetLanguage
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_ai_serenade_treesitter_TreeSitter_parserSetLanguage
  (JNIEnv *, jclass, jlong, jlong);

/*
 * Class:     ai_serenade_treesitter_TreeSitter
 * Method:    parserParseString
 * Signature: (JLjava/lang/String;I)J
 */
JNIEXPORT jlong JNICALL Java_ai_serenade_treesitter_TreeSitter_parserParseString
  (JNIEnv *, jclass, jlong, jstring, jint);

/*
 * Class:     ai_serenade_treesitter_TreeSitter
 * Method:    treeCursorNew
 * Signature: (Lai/serenade/treesitter/Node;)Lai/serenade/treesitter/TreeCursor;
 */
JNIEXPORT jobject JNICALL Java_ai_serenade_treesitter_TreeSitter_treeCursorNew
  (JNIEnv *, jclass, jobject);

/*
 * Class:     ai_serenade_treesitter_TreeSitter
 * Method:    treeCursorCurrentFieldName
 * Signature: (Lai/serenade/treesitter/TreeCursor;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_ai_serenade_treesitter_TreeSitter_treeCursorCurrentFieldName
  (JNIEnv *, jclass, jobject);

/*
 * Class:     ai_serenade_treesitter_TreeSitter
 * Method:    treeCursorCurrentNode
 * Signature: (Lai/serenade/treesitter/TreeCursor;)Lai/serenade/treesitter/Node;
 */
JNIEXPORT jobject JNICALL Java_ai_serenade_treesitter_TreeSitter_treeCursorCurrentNode
  (JNIEnv *, jclass, jobject);

/*
 * Class:     ai_serenade_treesitter_TreeSitter
 * Method:    treeCursorGotoFirstChild
 * Signature: (Lai/serenade/treesitter/TreeCursor;)Z
 */
JNIEXPORT jboolean JNICALL Java_ai_serenade_treesitter_TreeSitter_treeCursorGotoFirstChild
  (JNIEnv *, jclass, jobject);

/*
 * Class:     ai_serenade_treesitter_TreeSitter
 * Method:    treeCursorGotoNextSibling
 * Signature: (Lai/serenade/treesitter/TreeCursor;)Z
 */
JNIEXPORT jboolean JNICALL Java_ai_serenade_treesitter_TreeSitter_treeCursorGotoNextSibling
  (JNIEnv *, jclass, jobject);

/*
 * Class:     ai_serenade_treesitter_TreeSitter
 * Method:    treeCursorGotoParent
 * Signature: (Lai/serenade/treesitter/TreeCursor;)Z
 */
JNIEXPORT jboolean JNICALL Java_ai_serenade_treesitter_TreeSitter_treeCursorGotoParent
  (JNIEnv *, jclass, jobject);

/*
 * Class:     ai_serenade_treesitter_TreeSitter
 * Method:    treeDelete
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_ai_serenade_treesitter_TreeSitter_treeDelete
  (JNIEnv *, jclass, jlong);

/*
 * Class:     ai_serenade_treesitter_TreeSitter
 * Method:    treeRootNode
 * Signature: (J)Lai/serenade/treesitter/Node;
 */
JNIEXPORT jobject JNICALL Java_ai_serenade_treesitter_TreeSitter_treeRootNode
  (JNIEnv *, jclass, jlong);

#ifdef __cplusplus
}
#endif
#endif
