$NetBSD: patch-Source_JavaScriptCore_dfg_DFGDoesGC.cpp,v 1.1 2019/02/21 18:52:15 maya Exp $

Fix remote code execution in JavaScript. From upstream commit:

From d51ece4028133113e9e5d0f2576ad23489801ddc Mon Sep 17 00:00:00 2001
From: "mark.lam@apple.com"
 <mark.lam@apple.com@268f45cc-cd09-0410-ab3c-d52691b4dbfc>
Date: Tue, 19 Feb 2019 02:32:10 +0000
Subject: [PATCH] Fix DFG doesGC() for CompareEq/Less/LessEq/Greater/GreaterEq
 and CompareStrictEq nodes. https://bugs.webkit.org/show_bug.cgi?id=194800
 <rdar://problem/48183773>

Reviewed by Yusuke Suzuki.

Fix doesGC() for the following nodes:

    CompareEq:
    CompareLess:
    CompareLessEq:
    CompareGreater:
    CompareGreaterEq:
    CompareStrictEq:
        Only return false (i.e. does not GC) for child node use kinds that have
        been vetted to not do anything that can GC.  For all other use kinds
        (including StringUse and BigIntUse), we return true (i.e. does GC).

* dfg/DFGDoesGC.cpp:
(JSC::DFG::doesGC):


git-svn-id: http://svn.webkit.org/repository/webkit/trunk@241753 268f45cc-cd09-0410-ab3c-d52691b4dbfc

--- Source/JavaScriptCore/dfg/DFGDoesGC.cpp.orig	2019-02-08 16:17:00.000000000 +0000
+++ Source/JavaScriptCore/dfg/DFGDoesGC.cpp
@@ -146,14 +146,8 @@ bool doesGC(Graph& graph, Node* node)
     case RegExpTest:
     case RegExpMatchFast:
     case RegExpMatchFastGlobal:
-    case CompareLess:
-    case CompareLessEq:
-    case CompareGreater:
-    case CompareGreaterEq:
     case CompareBelow:
     case CompareBelowEq:
-    case CompareEq:
-    case CompareStrictEq:
     case CompareEqPtr:
     case SameValue:
     case Call:
@@ -374,6 +368,46 @@ bool doesGC(Graph& graph, Node* node)
     case MapSet:
         return true;
 
+    case CompareEq:
+    case CompareLess:
+    case CompareLessEq:
+    case CompareGreater:
+    case CompareGreaterEq:
+        if (node->isBinaryUseKind(Int32Use)
+#if USE(JSVALUE64)
+            || node->isBinaryUseKind(Int52RepUse)
+#endif
+            || node->isBinaryUseKind(DoubleRepUse)
+            || node->isBinaryUseKind(StringIdentUse)
+            )
+            return false;
+        if (node->op() == CompareEq) {
+            if (node->isBinaryUseKind(BooleanUse)
+                || node->isBinaryUseKind(SymbolUse)
+                || node->isBinaryUseKind(ObjectUse)
+                || node->isBinaryUseKind(ObjectUse, ObjectOrOtherUse) || node->isBinaryUseKind(ObjectOrOtherUse, ObjectUse))
+                return false;
+        }
+        return true;
+
+    case CompareStrictEq:
+        if (node->isBinaryUseKind(BooleanUse)
+            || node->isBinaryUseKind(Int32Use)
+#if USE(JSVALUE64)
+            || node->isBinaryUseKind(Int52RepUse)
+#endif
+            || node->isBinaryUseKind(DoubleRepUse)
+            || node->isBinaryUseKind(SymbolUse)
+            || node->isBinaryUseKind(SymbolUse, UntypedUse)
+            || node->isBinaryUseKind(UntypedUse, SymbolUse)
+            || node->isBinaryUseKind(StringIdentUse)
+            || node->isBinaryUseKind(ObjectUse, UntypedUse) || node->isBinaryUseKind(UntypedUse, ObjectUse)
+            || node->isBinaryUseKind(ObjectUse)
+            || node->isBinaryUseKind(MiscUse, UntypedUse) || node->isBinaryUseKind(UntypedUse, MiscUse)
+            || node->isBinaryUseKind(StringIdentUse, NotStringVarUse) || node->isBinaryUseKind(NotStringVarUse, StringIdentUse))
+            return false;
+        return true;
+
     case GetIndexedPropertyStorage:
         if (node->arrayMode().type() == Array::String)
             return true;
