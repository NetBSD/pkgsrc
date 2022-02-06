$NetBSD: patch-xfce4-session_xfsm-shutdown-fallback.c,v 1.3 2022/02/06 17:42:47 gutteridge Exp $

Fix compilation on OSes other than Linux and the *BSDs.

--- xfce4-session/xfsm-shutdown-fallback.c.orig	2020-11-06 23:08:55.000000000 +0000
+++ xfce4-session/xfsm-shutdown-fallback.c
@@ -373,7 +373,9 @@ xfsm_shutdown_fallback_try_action (XfsmS
                                    GError           **error)
 {
   const gchar *xfsm_helper_action;
-  const gchar *cmd __attribute__((unused));
+#ifdef __BACKEND_TYPE_BSD__
+  const gchar *cmd;
+#endif
   gboolean ret = FALSE;
   gint exit_status = 0;
 #ifdef HAVE_POLKIT
@@ -384,29 +386,39 @@ xfsm_shutdown_fallback_try_action (XfsmS
   {
     case XFSM_SHUTDOWN_SHUTDOWN:
       xfsm_helper_action = "shutdown";
+#ifdef __BACKEND_TYPE_BSD__
       cmd = POWEROFF_CMD;
+#endif
       break;
     case XFSM_SHUTDOWN_RESTART:
       xfsm_helper_action = "restart";
+#ifdef __BACKEND_TYPE_BSD__
       cmd = REBOOT_CMD;
+#endif
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
@@ -434,7 +446,7 @@ xfsm_shutdown_fallback_try_action (XfsmS
 #endif
   if (!ret)
     {
-      g_set_error (error, 1, 0, "Failed to %s (%s)", xfsm_helper_action, cmd);
+      g_set_error (error, 1, 0, "Failed to %s", xfsm_helper_action);
     }
   return ret;
 }
