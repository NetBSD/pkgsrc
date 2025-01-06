$NetBSD: patch-xfce4-session_xfsm-shutdown-fallback.c,v 1.4 2025/01/06 19:27:40 bsiegert Exp $

Fix compilation on OSes other than Linux and the *BSDs.

--- xfce4-session/xfsm-shutdown-fallback.c.orig	2024-11-04 16:33:53.000000000 +0000
+++ xfce4-session/xfsm-shutdown-fallback.c
@@ -343,7 +343,9 @@ xfsm_shutdown_fallback_try_action (XfsmS
                                    GError **error)
 {
   const gchar *xfsm_helper_action;
-  const gchar *cmd __attribute__ ((unused));
+#ifdef __BACKEND_TYPE_BSD__
+  const gchar *cmd;
+#endif
   gboolean ret = FALSE;
 #ifdef HAVE_POLKIT
   gchar *command = NULL;
@@ -353,23 +355,33 @@ xfsm_shutdown_fallback_try_action (XfsmS
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
       break;
     case XFSM_SHUTDOWN_HIBERNATE:
       xfsm_helper_action = "hibernate";
+#ifdef __BACKEND_TYPE_BSD__
       cmd = UP_BACKEND_HIBERNATE_COMMAND;
+#endif
       break;
     case XFSM_SHUTDOWN_HYBRID_SLEEP:
       xfsm_helper_action = "hybrid-sleep";
+#ifdef __BACKEND_TYPE_BSD__
       cmd = UP_BACKEND_HIBERNATE_COMMAND;
+#endif
       break;
     default:
       g_set_error (error, 1, 0, "Unknown shutdown type %d", type);
@@ -394,7 +406,7 @@ xfsm_shutdown_fallback_try_action (XfsmS
 #endif
   if (!ret)
     {
-      g_set_error (error, 1, 0, "Failed to %s (%s)", xfsm_helper_action, cmd);
+      g_set_error (error, 1, 0, "Failed to %s", xfsm_helper_action);
     }
   return ret;
 }
