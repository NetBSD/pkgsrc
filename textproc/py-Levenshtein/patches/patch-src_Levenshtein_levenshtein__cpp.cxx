$NetBSD: patch-src_Levenshtein_levenshtein__cpp.cxx,v 1.1 2026/09/26 07:56:02 wiz Exp $

Fix: "error: 'isfinite' was not declared"
https://github.com/rapidfuzz/Levenshtein/issues/99

--- src/Levenshtein/levenshtein_cpp.cxx.orig	2026-09-26 07:53:49.853977403 +0000
+++ src/Levenshtein/levenshtein_cpp.cxx
@@ -5997,7 +5997,7 @@ static int __Pyx_PyObject_CompareFloatIntBoolLt(PyObje
         Py_ssize_t iop2 = __Pyx_PyLong_CompactValue(op2);
         if (float_op1 < ((double)iop2)) goto __pyx_return_true; else goto __pyx_return_false;
     }
-    if (unlikely(!isfinite(float_op1))) {
+    if (unlikely(!std::isfinite(float_op1))) {
         if (float_op1 < 0.0) goto __pyx_return_true; else goto __pyx_return_false;
     } else {
         int sign2 = __Pyx_PyLong_Sign(op2);
@@ -6010,7 +6010,7 @@ static int __Pyx_PyObject_CompareFloatIntBoolLt(PyObje
         }
     }
     #else
-    if (unlikely(!isfinite(float_op1))) {
+    if (unlikely(!std::isfinite(float_op1))) {
         if (float_op1 < 0.0) goto __pyx_return_true; else goto __pyx_return_false;
     } else {
         int overflow2;
