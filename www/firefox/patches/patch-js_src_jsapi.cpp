$NetBSD: patch-js_src_jsapi.cpp,v 1.2 2015/02/19 21:33:22 ryoon Exp $

--- js/src/jsapi.cpp.orig	2015-01-23 06:00:01.000000000 +0000
+++ js/src/jsapi.cpp
@@ -236,7 +236,7 @@ JS_ConvertArgumentsVA(JSContext *cx, con
     assertSameCompartment(cx, args);
     required = true;
     while ((c = *format++) != '\0') {
-        if (isspace(c))
+        if (isspace(((unsigned char)c)))
             continue;
         if (c == '/') {
             required = false;
@@ -525,7 +525,7 @@ MessageParameterCount(const char *format
 {
     unsigned numfmtspecs = 0;
     for (const char *fmt = format; *fmt != '\0'; fmt++) {
-        if (*fmt == '{' && isdigit(fmt[1]))
+        if (*fmt == '{' && isdigit((unsigned char)fmt[1]))
             ++numfmtspecs;
     }
     return numfmtspecs;
