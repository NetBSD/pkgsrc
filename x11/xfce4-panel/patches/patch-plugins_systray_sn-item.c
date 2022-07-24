$NetBSD: patch-plugins_systray_sn-item.c,v 1.1 2022/07/24 20:46:33 gutteridge Exp $

Do not crash if a "NewStatus" signal is received. Xfce commit
https://gitlab.xfce.org/xfce/xfce4-panel/-/commit/5ec17b6d1166e7dc4a9fe7d45169252335bdf1da

--- plugins/systray/sn-item.c.orig	2022-04-16 11:39:02.000000000 +0000
+++ plugins/systray/sn-item.c
@@ -565,6 +565,13 @@ sn_item_signal_received (GDBusProxy *pro
     }
   else if (!g_strcmp0 (signal_name, "NewStatus"))
     {
+      finish_and_return_if_true (parameters == NULL);
+      if (! g_variant_check_format_string (parameters, "(s)", FALSE))
+        {
+          g_warning ("Could not parse properties for StatusNotifierItem.");
+          return;
+        }
+
       g_variant_get (parameters, "(s)", &status);
       exposed = sn_item_status_is_exposed (status);
       g_free (status);
