$NetBSD: patch-src_gs-auth-pam.c,v 1.1 2016/05/21 19:14:20 youri Exp $

Darwin build fix
XXX Fix properly

--- src/gs-auth-pam.c.orig	2015-10-06 15:32:23.000000000 +0000
+++ src/gs-auth-pam.c
@@ -526,7 +526,9 @@ gs_auth_thread_func (int auth_operation_
 
 	status = pam_authenticate (pam_handle, flags);
 
+#ifndef __APPLE__
 	sigtimedwait (&set, NULL, &timeout);
+#endif
 	unblock_sigchld ();
 
 	if (gs_auth_get_verbose ())
