$NetBSD: patch-qtdeclarative_src_qml_jsruntime_qv4globalobject.cpp,v 1.1 2014/07/14 16:32:14 jperkin Exp $

Avoid "error: call of overloaded <func> is ambiguous"

--- qtdeclarative/src/qml/jsruntime/qv4globalobject.cpp.orig	2014-02-01 20:38:02.000000000 +0000
+++ qtdeclarative/src/qml/jsruntime/qv4globalobject.cpp
@@ -534,7 +534,7 @@ ReturnedValue GlobalFunctions::method_pa
     }
 
     if (overflow) {
-        double result = (double) v_overflow * pow(R, overflow_digit_count);
+        double result = (double) v_overflow * pow((double)R, overflow_digit_count);
         result += v;
         return Encode(sign * result);
     } else {
