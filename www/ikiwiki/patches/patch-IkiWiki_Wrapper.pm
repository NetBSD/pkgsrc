$NetBSD: patch-IkiWiki_Wrapper.pm,v 1.3 2018/08/29 08:03:38 schmonz Exp $

Apply upstream patch 64aa6eb:
Need <sys/wait.h> for waitpid (NetBSD 8 warns).

--- IkiWiki/Wrapper.pm.orig	2018-03-11 15:54:34.000000000 +0000
+++ IkiWiki/Wrapper.pm
@@ -182,6 +182,7 @@ EOF
 #include <stdlib.h>
 #include <string.h>
 #include <sys/file.h>
+#include <sys/wait.h>
 
 extern char **environ;
 int newenvironlen=0;
