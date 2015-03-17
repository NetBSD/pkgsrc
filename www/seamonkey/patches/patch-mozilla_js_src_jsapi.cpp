$NetBSD: patch-mozilla_js_src_jsapi.cpp,v 1.3 2015/03/17 19:50:42 ryoon Exp $

--- mozilla/js/src/jsapi.cpp.orig	2015-03-09 05:34:38.000000000 +0000
+++ mozilla/js/src/jsapi.cpp
@@ -233,7 +233,7 @@ JS_ConvertArgumentsVA(JSContext *cx, con
     assertSameCompartment(cx, args);
     required = true;
     while ((c = *format++) != '\0') {
-        if (isspace(c))
+        if (isspace(((unsigned char)c)))
             continue;
         if (c == '/') {
             required = false;
@@ -522,7 +522,7 @@ MessageParameterCount(const char *format
 {
     unsigned numfmtspecs = 0;
     for (const char *fmt = format; *fmt != '\0'; fmt++) {
-        if (*fmt == '{' && isdigit(fmt[1]))
+        if (*fmt == '{' && isdigit((unsigned char)fmt[1]))
             ++numfmtspecs;
     }
     return numfmtspecs;
