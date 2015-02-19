$NetBSD: patch-js_src_shell_jsoptparse.cpp,v 1.2 2015/02/19 21:33:22 ryoon Exp $

--- js/src/shell/jsoptparse.cpp.orig	2015-01-23 06:00:02.000000000 +0000
+++ js/src/shell/jsoptparse.cpp
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
