$NetBSD: patch-mozilla_js_src_shell_jsoptparse.cpp,v 1.3 2015/10/02 22:49:36 ryoon Exp $

--- mozilla/js/src/shell/jsoptparse.cpp.orig	2015-09-25 07:35:49.000000000 +0000
+++ mozilla/js/src/shell/jsoptparse.cpp
@@ -95,7 +95,7 @@ PrintParagraph(const char* text, unsigne
         ++it;
 
     while (*it != '\0') {
-        MOZ_ASSERT(!isspace(*it));
+        MOZ_ASSERT(!isspace((unsigned char)*it));
 
         /* Delimit the current token. */
         const char* limit = it;
