$NetBSD: patch-IkiWiki_Wrapper.pm,v 1.1 2013/09/15 16:26:11 schmonz Exp $

Specify return type to quell clang warnings.

--- IkiWiki/Wrapper.pm.orig	2013-09-03 18:53:37.000000000 +0000
+++ IkiWiki/Wrapper.pm
@@ -182,7 +182,7 @@ void addenv(char *var, char *val) {
 	newenviron[i++]=s;
 }
 
-set_cgilock_fd (int lockfd) {
+void set_cgilock_fd (int lockfd) {
 	char *fd_s=malloc(8);
 	sprintf(fd_s, "%i", lockfd);
 	setenv("IKIWIKI_CGILOCK_FD", fd_s, 1);
