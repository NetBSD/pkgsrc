$NetBSD: patch-xfce4-session_xfsm-shutdown-fallback.c,v 1.1 2020/03/01 19:47:23 gutteridge Exp $

Fix compilation on OSes other than Linux and the *BSDs.

--- xfce4-session/xfsm-shutdown-fallback.c.orig	2019-05-17 12:46:28.000000000 +0000
+++ xfce4-session/xfsm-shutdown-fallback.c
@@ -371,7 +371,9 @@ xfsm_shutdown_fallback_try_action (XfsmS
                                    GError           **error)
 {
   const gchar *xfsm_helper_action;
+#ifdef __BACKEND_TYPE_BSD__
   const gchar *cmd __attribute__((unused));
+#endif
   gboolean ret = FALSE;
   gint exit_status = 0;
 #ifdef HAVE_POLKIT
@@ -390,21 +392,27 @@ xfsm_shutdown_fallback_try_action (XfsmS
       break;
     case XFSM_SHUTDOWN_SUSPEND:
       xfsm_helper_action = "suspend";
+#ifdef __BACKEND_TYPE_BSD__
       cmd = UP_BACKEND_SUSPEND_COMMAND;
+#endif
       /* On suspend we try to lock the screen */
       if (!lock_screen (error))
         return FALSE;
       break;
     case XFSM_SHUTDOWN_HIBERNATE:
       xfsm_helper_action = "hibernate";
+#ifdef __BACKEND_TYPE_BSD__
       cmd = UP_BACKEND_HIBERNATE_COMMAND;
+#endif
       /* On hibernate we try to lock the screen */
       if (!lock_screen (error))
         return FALSE;
       break;
     case XFSM_SHUTDOWN_HYBRID_SLEEP:
       xfsm_helper_action = "hybrid-sleep";
+#ifdef __BACKEND_TYPE_BSD__
       cmd = UP_BACKEND_HIBERNATE_COMMAND;
+#endif
       /* On hybrid sleep we try to lock the screen */
       if (!lock_screen (error))
         return FALSE;
