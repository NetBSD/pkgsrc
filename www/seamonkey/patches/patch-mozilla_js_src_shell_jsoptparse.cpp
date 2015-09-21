$NetBSD: patch-mozilla_js_src_shell_jsoptparse.cpp,v 1.2 2015/09/21 05:03:45 ryoon Exp $

--- mozilla/js/src/shell/jsoptparse.cpp.orig	2015-09-02 09:27:36.000000000 +0000
+++ mozilla/js/src/shell/jsoptparse.cpp
@@ -90,7 +90,7 @@ PrintParagraph(const char* text, unsigne
         printf("%*s", startColno, "");
 
     while (*it != '\0') {
-        MOZ_ASSERT(!isspace(*it));
+        MOZ_ASSERT(!isspace((unsigned char)*it));
 
         /* Delimit the current token. */
         const char* limit = it;
