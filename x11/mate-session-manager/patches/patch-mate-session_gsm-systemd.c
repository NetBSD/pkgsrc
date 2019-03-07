$NetBSD: patch-mate-session_gsm-systemd.c,v 1.3 2019/03/07 01:26:46 gutteridge Exp $

Deal with systemd-only function calls.

--- mate-session/gsm-systemd.c.orig	2019-02-10 13:54:15.000000000 +0000
+++ mate-session/gsm-systemd.c
@@ -427,15 +427,19 @@ gsm_systemd_is_last_session_for_user (Gs
         char **sessions = NULL;
         char *session = NULL;
         gboolean is_last_session;
-        int ret, i;
+        int ret = 1, i;
 
+#ifdef HAVE_SYSTEMD
         ret = sd_pid_get_session (getpid (), &session);
+#endif
 
         if (ret != 0) {
                 return FALSE;
         }
 
+#ifdef HAVE_SYSTEMD
         ret = sd_uid_get_sessions (getuid (), FALSE, &sessions);
+#endif
 
         if (ret <= 0) {
                 free (session);
@@ -450,7 +454,9 @@ gsm_systemd_is_last_session_for_user (Gs
                 if (g_strcmp0 (sessions[i], session) == 0)
                         continue;
 
+#ifdef HAVE_SYSTEMD
                 ret = sd_session_get_state (sessions[i], &state);
+#endif
 
                 if (ret != 0)
                         continue;
@@ -461,7 +467,9 @@ gsm_systemd_is_last_session_for_user (Gs
                 }
                 free (state);
 
+#ifdef HAVE_SYSTEMD
                 ret = sd_session_get_type (sessions[i], &type);
+#endif
 
                 if (ret != 0)
                         continue;
