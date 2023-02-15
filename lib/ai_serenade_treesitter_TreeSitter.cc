#include "ai_serenade_treesitter_TreeSitter.h"

#include <jni.h>
#include <string.h>
#include <tree_sitter/api.h>
#include <iostream>

struct TreeCursorNode {
  const char* type;
  const char* name;
  uint32_t startByte;
  uint32_t endByte;
};

static jint JNI_VERSION = JNI_VERSION_1_6;


// Node
static jclass _nodeClass;
static jfieldID _nodeContext0Field;
static jfieldID _nodeContext1Field;
static jfieldID _nodeContext2Field;
static jfieldID _nodeContext3Field;
static jfieldID _nodeIdField;
static jfieldID _nodeTreeField;

// TreeCursorNode
static jclass _treeCursorNodeClass;
static jfieldID _treeCursorNodeTypeField;
static jfieldID _treeCursorNodeNameField;
static jfieldID _treeCursorNodeStartByteField;
static jfieldID _treeCursorNodeEndByteField;

// TSPoint
static jclass _pointClass;
static jfieldID _pointRowField;
static jfieldID _pointColumnField;

// TSInputEdit
static jclass _inputEditClass;
static jfieldID _inputEditStartByteField;
static jfieldID _inputEditOldEndByteField;
static jfieldID _inputEditNewEndByteField;
static jfieldID _inputEditStartPointField;
static jfieldID _inputEditOldEndPointField;
static jfieldID _inputEditNewEndPointField;

// TSRange
static jclass _rangeClass;
static jfieldID _rangeStartPointField;
static jfieldID _rangeEndPointField;
static jfieldID _rangeStartByteField;
static jfieldID _rangeEndByteField;

// TSQueryCursor
static jclass _queryCursorClass;

// TSQueryMatch
static jclass _queryMatchClass;
static jfieldID _queryMatchIdField;
static jfieldID _queryMatchPatternIndexField;
static jfieldID _queryMatchCapturesField;

// TSQueryCapture
static jclass _queryCaptureClass;
static jfieldID _queryCaptureNode;
static jfieldID _queryCaptureIndex;


#define _loadClass(VARIABLE, NAME)             \
  {                                            \
    jclass tmp;                                \
    tmp = env->FindClass(NAME);                \
    VARIABLE = (jclass)env->NewGlobalRef(tmp); \
    env->DeleteLocalRef(tmp);                  \
  }

#define _loadField(VARIABLE, CLASS, NAME, TYPE) \
  { VARIABLE = env->GetFieldID(CLASS, NAME, TYPE); }


jint JNI_OnLoad(JavaVM* vm, void* reserved) {
  JNIEnv* env;
  if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION) != JNI_OK) {
    return JNI_ERR;
  }

  // Node
  _loadClass(_nodeClass, "ai/serenade/treesitter/Node");
  _loadField(_nodeContext0Field, _nodeClass, "context0", "I");
  _loadField(_nodeContext1Field, _nodeClass, "context1", "I");
  _loadField(_nodeContext2Field, _nodeClass, "context2", "I");
  _loadField(_nodeContext3Field, _nodeClass, "context3", "I");
  _loadField(_nodeIdField, _nodeClass, "id", "J");
  _loadField(_nodeTreeField, _nodeClass, "tree", "J");

  // TreeCursorNode
  _loadClass(_treeCursorNodeClass, "ai/serenade/treesitter/TreeCursorNode");
  _loadField(_treeCursorNodeTypeField, _treeCursorNodeClass, "type",
             "Ljava/lang/String;");
  _loadField(_treeCursorNodeNameField, _treeCursorNodeClass, "name",
             "Ljava/lang/String;");
  _loadField(_treeCursorNodeStartByteField, _treeCursorNodeClass, "startByte",
             "I");
  _loadField(_treeCursorNodeEndByteField, _treeCursorNodeClass, "endByte", "I");

  // TSPoint
  _loadClass(_pointClass, "ai/serenade/treesitter/TSPoint");
  _loadField(_pointRowField, _pointClass, "row", "I");
  _loadField(_pointColumnField, _pointClass, "column", "I");

  // TSInputEdit
  _loadClass(_inputEditClass, "ai/serenade/treesitter/TSInputEdit");
  _loadField(_inputEditStartByteField, _inputEditClass, "startByte", "I");
  _loadField(_inputEditOldEndByteField, _inputEditClass, "oldEndByte", "I");
  _loadField(_inputEditNewEndByteField, _inputEditClass, "newEndByte", "I");
  _loadField(_inputEditStartPointField, _inputEditClass, "start_point", "Lai/serenade/treesitter/TSPoint;");
  _loadField(_inputEditOldEndPointField, _inputEditClass, "old_end_point", "Lai/serenade/treesitter/TSPoint;");
  _loadField(_inputEditNewEndPointField, _inputEditClass, "new_end_point", "Lai/serenade/treesitter/TSPoint;");

  // TSRange
  _loadClass(_rangeClass, "ai/serenade/treesitter/TSRange");
  _loadField(_rangeStartByteField, _rangeClass, "start_byte", "I");
  _loadField(_rangeEndByteField, _rangeClass, "end_byte", "I");
  _loadField(_rangeStartPointField, _rangeClass, "start_point", "Lai/serenade/treesitter/TSPoint;");
  _loadField(_rangeEndPointField, _rangeClass, "end_point", "Lai/serenade/treesitter/TSPoint;");

  // TSQueryCursor
  _loadClass(_queryCursorClass, "ai/serenade/treesitter/TSQueryCursor");

  // TSQueryCapture
  _loadClass(_queryCaptureClass, "ai/serenade/treesitter/TSQueryCapture");
  _loadField(_queryCaptureNode, _queryCaptureClass, "node", "Lai/serenade/treesitter/Node;");
  _loadField(_queryCaptureIndex, _queryCaptureClass, "index", "I");

  // TSQueryMatch
  _loadClass(_queryMatchClass, "ai/serenade/treesitter/TSQueryMatch");
  _loadField(_queryMatchIdField, _queryMatchClass, "id", "I");
  _loadField(_queryMatchPatternIndexField, _queryMatchClass, "pattern_index", "I");
  _loadField(_queryMatchCapturesField, _queryMatchClass, "captures", "[Lai/serenade/treesitter/TSQueryCapture;");

  return JNI_VERSION;
}

void JNI_OnUnload(JavaVM* vm, void* reserved) {
  JNIEnv* env;
  vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION);

  env->DeleteGlobalRef(_nodeClass);
  env->DeleteGlobalRef(_treeCursorNodeClass);
}

// Node
jobject _marshalNode(JNIEnv* env, TSNode node) {
  jobject javaObject = env->AllocObject(_nodeClass);
  env->SetIntField(javaObject, _nodeContext0Field, node.context[0]);
  env->SetIntField(javaObject, _nodeContext1Field, node.context[1]);
  env->SetIntField(javaObject, _nodeContext2Field, node.context[2]);
  env->SetIntField(javaObject, _nodeContext3Field, node.context[3]);
  env->SetLongField(javaObject, _nodeIdField, (jlong)node.id);
  env->SetLongField(javaObject, _nodeTreeField, (jlong)node.tree);
  return javaObject;
}

jobject _marshalCapture(JNIEnv* env, TSQueryCapture capture) {
  jobject javaObject = env->AllocObject(_queryCaptureClass);
  env->SetIntField(javaObject, _queryCaptureIndex, capture.index);
  env->SetObjectField(javaObject, _queryCaptureNode, _marshalNode(env, capture.node));

  return javaObject;
}

// TSQueryMatch
jobject _marshalQueryMatch(JNIEnv* env, TSQueryMatch match) {
  jobject javaObject = env->AllocObject(_queryMatchClass);
  env->SetIntField(javaObject, _queryMatchIdField, match.id);
  env->SetIntField(javaObject, _queryMatchPatternIndexField, match.pattern_index);

  jobjectArray captures = (*env).NewObjectArray(match.capture_count, _queryCaptureClass, NULL);
  for (int i = 0; i < match.capture_count; i++) {
    env->SetObjectArrayElement(captures, i, _marshalCapture(env, match.captures[i]));
  }
  env->SetObjectField(javaObject, _queryMatchCapturesField, captures);


  return javaObject;
}



TSNode _unmarshalNode(JNIEnv* env, jobject javaObject) {
  return (TSNode) {
    {
      (uint32_t)env->GetIntField(javaObject, _nodeContext0Field),
      (uint32_t)env->GetIntField(javaObject, _nodeContext1Field),
      (uint32_t)env->GetIntField(javaObject, _nodeContext2Field),
      (uint32_t)env->GetIntField(javaObject, _nodeContext3Field),
    },
    (const void*)env->GetLongField(javaObject, _nodeIdField),
    (const TSTree*)env->GetLongField(javaObject, _nodeTreeField)
  };
}

// TreeCursorNode
jobject _marshalTreeCursorNode(JNIEnv* env, TreeCursorNode node) {
  jobject javaObject = env->AllocObject(_treeCursorNodeClass);
  env->SetObjectField(javaObject, _treeCursorNodeTypeField,
                      env->NewStringUTF(node.type));
  env->SetObjectField(javaObject, _treeCursorNodeNameField,
                      env->NewStringUTF(node.name));
  env->SetIntField(javaObject, _treeCursorNodeStartByteField, node.startByte);
  env->SetIntField(javaObject, _treeCursorNodeEndByteField, node.endByte);
  return javaObject;
}

// Point
// Not sure why I need to divide by two, probably because of utf-16
jobject _marshalPoint(JNIEnv* env, TSPoint point) {
  jobject javaObject = env->AllocObject(_pointClass);

  env->SetIntField(javaObject, _pointRowField, point.row);
  env->SetIntField(javaObject, _pointColumnField, point.column / 2);
  return javaObject;
}

jobject _marshalRange(JNIEnv* env, TSRange range) {
  jobject javaObject = env->AllocObject(_rangeClass);

  env->SetObjectField(javaObject, _rangeStartPointField, _marshalPoint(env, range.start_point));
  env->SetObjectField(javaObject, _rangeEndPointField, _marshalPoint(env, range.end_point));
  env->SetIntField(javaObject, _rangeStartByteField, range.start_byte);
  env->SetIntField(javaObject, _rangeEndByteField, range.end_byte);
  return javaObject;
}


TSPoint _unmarshalPoint(JNIEnv* env, jobject javaObject) {
  return (TSPoint) {
    (uint32_t)env->GetIntField(javaObject, _pointRowField),
    (uint32_t)env->GetIntField(javaObject, _pointColumnField),
  };
}

// TSInputEdit
TSInputEdit _unmarshalInputEdit(JNIEnv* env, jobject inputEdit) {
  return (TSInputEdit) {
    (uint32_t)env->GetIntField(inputEdit, _inputEditStartByteField),
    (uint32_t)env->GetIntField(inputEdit, _inputEditOldEndByteField),
    (uint32_t)env->GetIntField(inputEdit, _inputEditNewEndByteField),   
    _unmarshalPoint(env, env->GetObjectField(inputEdit, _inputEditStartPointField)),
    _unmarshalPoint(env, env->GetObjectField(inputEdit, _inputEditOldEndPointField)),
    _unmarshalPoint(env, env->GetObjectField(inputEdit, _inputEditNewEndPointField)),
  };
}


JNIEXPORT jobject JNICALL Java_ai_serenade_treesitter_TreeSitter_nodeChild(
  JNIEnv* env, jclass self, jobject node, jint child) {
  return _marshalNode(
           env, ts_node_child(_unmarshalNode(env, node), (uint32_t)child));
}

JNIEXPORT jobject JNICALL Java_ai_serenade_treesitter_TreeSitter_nodeParent(
  JNIEnv* env, jclass self, jobject node) {


  TSNode ts_node = _unmarshalNode(env, node);
  TSNode parent = ts_node_parent(ts_node);
  if (ts_node_is_null(parent)) {
    return NULL;
  }

  return _marshalNode(env, parent);
}

JNIEXPORT jint JNICALL Java_ai_serenade_treesitter_TreeSitter_nodeChildCount(
  JNIEnv* env, jclass self, jobject node) {
  return (jint)ts_node_child_count(_unmarshalNode(env, node));
}

JNIEXPORT jstring JNICALL Java_ai_serenade_treesitter_TreeSitter_nodeString(
  JNIEnv* env, jclass self, jobject node) {
  char* nodeString = ts_node_string(_unmarshalNode(env, node));
  jstring result = env->NewStringUTF(nodeString);
  free(nodeString);
  return result;
}

JNIEXPORT jint JNICALL Java_ai_serenade_treesitter_TreeSitter_nodeEndByte(
  JNIEnv* env, jclass self, jobject node) {
  return (jint)ts_node_end_byte(_unmarshalNode(env, node)) / 2;
}

JNIEXPORT jint JNICALL Java_ai_serenade_treesitter_TreeSitter_nodeStartByte(
  JNIEnv* env, jclass self, jobject node) {
  return (jint)ts_node_start_byte(_unmarshalNode(env, node)) / 2;
}

JNIEXPORT jobject JNICALL Java_ai_serenade_treesitter_TreeSitter_nodeStartPoint(
  JNIEnv* env, jclass self, jobject node) {
  return _marshalPoint(env, ts_node_start_point(_unmarshalNode(env, node)));
}

JNIEXPORT jobject JNICALL Java_ai_serenade_treesitter_TreeSitter_nodeEndPoint(
  JNIEnv* env, jclass self, jobject node) {
  return _marshalPoint(env, ts_node_end_point(_unmarshalNode(env, node)));
}


JNIEXPORT jstring JNICALL Java_ai_serenade_treesitter_TreeSitter_nodeType(
  JNIEnv* env, jclass self, jobject node) {
  const char* type = ts_node_type(_unmarshalNode(env, node));
  jstring result = env->NewStringUTF(type);
  return result;
}

JNIEXPORT jboolean JNICALL Java_ai_serenade_treesitter_TreeSitter_nodeIsNamed(
  JNIEnv* env, jclass self, jobject node) {
  return (jboolean) ts_node_is_named(_unmarshalNode(env, node));
}

JNIEXPORT jboolean JNICALL Java_ai_serenade_treesitter_TreeSitter_nodeIsExtra(
  JNIEnv* env, jclass self, jobject node) {
  return (jboolean) ts_node_is_extra(_unmarshalNode(env, node));
}

JNIEXPORT jlong JNICALL
Java_ai_serenade_treesitter_TreeSitter_parserNew(JNIEnv* env, jclass self) {
  return (jlong)ts_parser_new();
}

JNIEXPORT void JNICALL Java_ai_serenade_treesitter_TreeSitter_parserDelete(
  JNIEnv* env, jclass self, jlong parser) {
  ts_parser_delete((TSParser*)parser);
}

JNIEXPORT void JNICALL Java_ai_serenade_treesitter_TreeSitter_parserSetLanguage(
  JNIEnv* env, jclass self, jlong parser, jlong language) {
  ts_parser_set_language((TSParser*)parser, (TSLanguage*)language);
}

JNIEXPORT jlong JNICALL Java_ai_serenade_treesitter_TreeSitter_parserParseBytes(
  JNIEnv* env, jclass self, jlong parser, jbyteArray source_bytes,
  jint length) {
  jbyte* source = env->GetByteArrayElements(source_bytes, NULL);
  printf("%p\n" , ts_parser_language(((TSParser*) parser)));
  jlong result = (jlong)ts_parser_parse_string_encoding(
                   (TSParser*)parser, NULL, reinterpret_cast<const char*>(source), length, TSInputEncodingUTF16);
  env->ReleaseByteArrayElements(source_bytes, source, JNI_ABORT);
  return result;
}

JNIEXPORT jlong JNICALL Java_ai_serenade_treesitter_TreeSitter_parserIncrementalParseBytes(
  JNIEnv* env, jclass self, jlong parser, jlong old_tree, jbyteArray source_bytes,
  jint length) {
  jbyte* source = env->GetByteArrayElements(source_bytes, NULL);
  jlong result = (jlong)ts_parser_parse_string_encoding(
                   (TSParser*)parser, (TSTree*)old_tree, reinterpret_cast<const char*>(source), length, TSInputEncodingUTF16);
  env->ReleaseByteArrayElements(source_bytes, source, JNI_ABORT);
  return result;
}


JNIEXPORT void JNICALL Java_ai_serenade_treesitter_TreeSitter_treeEdit(
  JNIEnv* env, jclass self, jlong tree, jobject inputEdit) {

  TSInputEdit edit = _unmarshalInputEdit(env, inputEdit);
  ts_tree_edit((TSTree*) tree, &edit);
}

JNIEXPORT jobjectArray JNICALL Java_ai_serenade_treesitter_TreeSitter_treeGetChangedRanges(
  JNIEnv* env, jclass self, jlong old_tree, jlong new_tree) {
  uint32_t length = 0;
  TSRange* range = ts_tree_get_changed_ranges((TSTree*) old_tree, (TSTree*) new_tree,  &length);
  jobjectArray result = (*env).NewObjectArray(length, _rangeClass, NULL);
  for (int i = 0; i < length; i++) {
    env->SetObjectArrayElement(result,i,_marshalRange(env,range[i]));
  }


  return result;
}

JNIEXPORT jlong JNICALL Java_ai_serenade_treesitter_TreeSitter_treeCursorNew(
  JNIEnv* env, jclass self, jobject node) {
  TSTreeCursor* cursor =
    new TSTreeCursor(ts_tree_cursor_new(_unmarshalNode(env, node)));
  return (jlong)cursor;
}

JNIEXPORT jstring JNICALL
Java_ai_serenade_treesitter_TreeSitter_treeCursorCurrentFieldName(
  JNIEnv* env, jclass self, jlong cursor) {
  const char* name = ts_tree_cursor_current_field_name((TSTreeCursor*)cursor);
  jstring result = env->NewStringUTF(name);
  return result;
}

JNIEXPORT jobject JNICALL
Java_ai_serenade_treesitter_TreeSitter_treeCursorCurrentNode(JNIEnv* env,
    jclass self,
    jlong cursor) {
  return _marshalNode(env, ts_tree_cursor_current_node((TSTreeCursor*)cursor));
}

JNIEXPORT jobject JNICALL
Java_ai_serenade_treesitter_TreeSitter_treeCursorCurrentTreeCursorNode(
  JNIEnv* env, jclass self, jlong cursor) {
  TSNode node = ts_tree_cursor_current_node((TSTreeCursor*)cursor);
  return _marshalTreeCursorNode(
           env,
  (TreeCursorNode) {
    ts_node_type(node),
                 ts_tree_cursor_current_field_name((TSTreeCursor*)cursor),
                 ts_node_start_byte(node) / 2, ts_node_end_byte(node) / 2
  });
}

JNIEXPORT void JNICALL Java_ai_serenade_treesitter_TreeSitter_treeCursorDelete(
  JNIEnv* env, jclass self, jlong cursor) {
  free((TSTreeCursor*) cursor);
}

JNIEXPORT jboolean JNICALL
Java_ai_serenade_treesitter_TreeSitter_treeCursorGotoFirstChild(JNIEnv* env,
    jclass self,
    jlong cursor) {
  return (jboolean)ts_tree_cursor_goto_first_child((TSTreeCursor*)cursor);
}

JNIEXPORT jboolean JNICALL
Java_ai_serenade_treesitter_TreeSitter_treeCursorGotoNextSibling(JNIEnv* env,
    jclass self,
    jlong cursor) {
  return (jboolean)ts_tree_cursor_goto_next_sibling((TSTreeCursor*)cursor);
}

JNIEXPORT jboolean JNICALL
Java_ai_serenade_treesitter_TreeSitter_treeCursorGotoParent(JNIEnv* env,
    jclass self,
    jlong cursor) {
  return (jboolean)ts_tree_cursor_goto_parent((TSTreeCursor*)cursor);
}

JNIEXPORT void JNICALL Java_ai_serenade_treesitter_TreeSitter_treeDelete(
  JNIEnv* env, jclass self, jlong tree) {
  ts_tree_delete((TSTree*)tree);
}

JNIEXPORT jobject JNICALL Java_ai_serenade_treesitter_TreeSitter_treeRootNode(
  JNIEnv* env, jclass self, jlong tree) {
  return _marshalNode(env, ts_tree_root_node((TSTree*)tree));
}

// Queries
JNIEXPORT jlong JNICALL Java_ai_serenade_treesitter_TreeSitter_tsQueryNew(
  JNIEnv* env, jclass self, jlong language, jstring source) {

  const char* c_source;
  uint32_t source_length = env->GetStringLength(source);
  c_source = env->GetStringUTFChars(source, NULL);
  uint32_t* error_offset = (uint32_t*) malloc(sizeof(uint32_t));
  TSQueryError* error_type = (TSQueryError*) malloc(sizeof(TSQueryError));
  TSQuery* query = ts_query_new((TSLanguage*) language, c_source, source_length, error_offset, error_type);
  return (jlong) query;
}

JNIEXPORT jlong JNICALL Java_ai_serenade_treesitter_TreeSitter_tsQueryCursorNew(
  JNIEnv* env, jclass self) {
  TSQueryCursor* cursor = ts_query_cursor_new();
  return (jlong) cursor;
}

JNIEXPORT void JNICALL Java_ai_serenade_treesitter_TreeSitter_tsQueryCursorExec(
  JNIEnv* env, jclass self, jlong query_cursor, jlong query, jobject node) {
  ts_query_cursor_exec((TSQueryCursor*) query_cursor, (TSQuery*) query, _unmarshalNode(env,node));
}

JNIEXPORT jobject JNICALL Java_ai_serenade_treesitter_TreeSitter_tsQueryCursorNextMatch
  (JNIEnv * env, jclass self, jlong query_cursor) {
    TSQueryMatch query_match;

    bool found = ts_query_cursor_next_match((TSQueryCursor*)query_cursor, &query_match);

    if (!found) {
      return NULL;
    }

    return _marshalQueryMatch(env, query_match);
}
