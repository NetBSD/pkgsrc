$NetBSD: patch-mozilla_js_src_shell_jsoptparse.cpp,v 1.1 2015/03/17 19:50:42 ryoon Exp $

--- mozilla/js/src/shell/jsoptparse.cpp.orig	2015-03-09 05:34:41.000000000 +0000
+++ mozilla/js/src/shell/jsoptparse.cpp
@@ -90,11 +90,11 @@ PrintParagraph(const char *text, unsigne
         printf("%*s", startColno, "");
 
     while (*it != '\0') {
-        MOZ_ASSERT(!isspace(*it));
+        MOZ_ASSERT(!isspace((unsigned char)*it));
 
         /* Delimit the current token. */
         const char *limit = it;
-        while (!isspace(*limit) && *limit != '\0')
+        while (!isspace(((unsigned char)*limit)) && *limit != '\0')
             ++limit;
 
         /*
