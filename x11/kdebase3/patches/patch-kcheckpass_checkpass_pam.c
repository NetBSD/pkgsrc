$NetBSD: patch-kcheckpass_checkpass_pam.c,v 1.1.2.2 2011/11/20 10:36:31 tron Exp $

Don't allow pam_service to be a path.

--- kcheckpass/checkpass_pam.c.orig	2007-10-08 09:51:09.000000000 +0000
+++ kcheckpass/checkpass_pam.c
@@ -147,6 +147,8 @@ AuthReturn Authenticate(const char *call
     PAM_data.classic = 1;
     pam_service = caller;
   }
+  if (strchr(pam_service, '/'))   /* service shouldn't be a path */
+    return AuthError;
   pam_error = pam_start(pam_service, user, &PAM_conversation, &pamh);
   if (pam_error != PAM_SUCCESS)
     return AuthError;
