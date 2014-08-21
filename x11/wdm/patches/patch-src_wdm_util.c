$NetBSD: patch-src_wdm_util.c,v 1.1 2014/08/21 15:52:00 jperkin Exp $

Fix build on systems with no sigsetmask().

--- src/wdm/util.c.orig	2005-03-26 13:57:04.000000000 +0000
+++ src/wdm/util.c
@@ -114,7 +114,11 @@ CleanUpChild (void)
 	setsid();
 #else
 	setpgid (0, getpid ());
+#  ifndef X_NOT_POSIX
+	sigprocmask(SIG_SETMASK, 0, (sigset_t *)NULL);
+#  else
 	sigsetmask (0);
+#  endif
 #endif
 #ifdef SIGCHLD
 	(void) Signal (SIGCHLD, SIG_DFL);
