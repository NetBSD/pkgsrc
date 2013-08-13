$NetBSD: patch-src_notification.c,v 1.1 2013/08/13 08:50:14 obache Exp $

* Require libnotify 0.6.1
  https://git.gnome.org/browse/zenity/commit/src/notification.c?id=620d5505c59b5b5dd092bfa35bdf3e7723f1e7c3

--- src/notification.c.orig	2010-11-15 22:07:54.000000000 +0000
+++ src/notification.c
@@ -24,75 +24,32 @@
 
 #include <config.h>
 
+#include <unistd.h>
+#include <stdlib.h>
 #include <gtk/gtk.h>
 #include <time.h>
 #include <string.h>
 
-#ifdef HAVE_LIBNOTIFY
 #include <libnotify/notify.h>
-#endif
 
 #include "zenity.h"
 #include "util.h"
 
-static GtkStatusIcon *status_icon;
-static gchar *icon_file;
-static const gchar *icon_stock;
-static gint icon_size;
+static char *icon_file;
 
 static void
-zenity_notification_icon_update (void)
+on_notification_default_action (NotifyNotification *n,
+                                const char         *action,
+                                void               *user_data)
 {
-  GdkPixbuf *pixbuf;
-  GError *error = NULL;
-
-  pixbuf = gdk_pixbuf_new_from_file_at_scale (icon_file, icon_size, icon_size, TRUE, &error);
-
-  if (error) {
-    g_warning ("Could not load notification icon '%s': %s",
-               icon_file, error->message);
-    g_clear_error (&error);
-  }
-  if (!pixbuf) {
-    pixbuf = gdk_pixbuf_new_from_file_at_scale (ZENITY_IMAGE_FULLPATH ("zenity-notification.png"),
-                                                icon_size, icon_size, TRUE, NULL);
-  }
-
-  gtk_status_icon_set_from_pixbuf (status_icon, pixbuf);
-
-  if (pixbuf) {
-    g_object_unref (pixbuf);
-  }
-}
-
-static gboolean
-zenity_notification_icon_size_changed_cb (GtkStatusIcon *icon,
-					  gint size,
-					  gpointer user_data)
-{
-  icon_size = size;
-
-  /* If we're displaying not a stock icon but a custom pixbuf,
-   * we need to update the icon for the new size.
-   */
-  if (!icon_stock) {
-    zenity_notification_icon_update ();
-
-    return TRUE;
-  }
+  ZenityData *zen_data;
 
-  return FALSE;
-}
+  zen_data = (ZenityData *)user_data;
+  notify_notification_close (n, NULL);
 
-static gboolean
-zenity_notification_icon_activate_cb (GtkWidget *widget,
-				      ZenityData *data)
-{
-  data->exit_code = zenity_util_return_exit_code (ZENITY_OK);
+  zen_data->exit_code = zenity_util_return_exit_code (ZENITY_OK);
 
   gtk_main_quit ();
-
-  return TRUE;
 }
 
 static gboolean
@@ -145,26 +102,16 @@ zenity_notification_handle_stdin (GIOCha
       while (*value && g_ascii_isspace (*value)) value++;
 
       if (!g_ascii_strcasecmp (command, "icon")) {
-        icon_stock = zenity_util_stock_from_filename (value);
 
         g_free (icon_file);
         icon_file = g_strdup (value);
 
-        if (icon_stock) {
-          gtk_status_icon_set_from_stock (status_icon, icon_stock);
-        } else if (gtk_status_icon_get_visible (status_icon) &&
-                   gtk_status_icon_is_embedded (status_icon)) {
-          zenity_notification_icon_update ();
-        }
       } else if (!g_ascii_strcasecmp (command, "message")) {
-#ifdef HAVE_LIBNOTIFY
         /* display a notification bubble */
         if (!g_utf8_validate (value, -1, NULL)) {
           g_warning ("Invalid UTF-8 in input!");
-        } else if (notify_is_initted ()) {
+        } else {
           NotifyNotification *notif;
-          const gchar *icon = NULL;
-          gchar *freeme = NULL;
           gchar **message;
           error = NULL;
 
@@ -178,19 +125,12 @@ zenity_notification_handle_stdin (GIOCha
             continue;
           }
 
-          if (icon_stock) {
-            icon = icon_stock;
-          } else if (icon_file) {
-            icon = freeme = g_filename_to_uri (icon_file, NULL, NULL);
-          }
-
-          notif = notify_notification_new_with_status_icon (
+          notif = notify_notification_new (
                               message[0] /* title */,
                               message[1] /* summary */,
-                              icon, status_icon);
+                              icon_file);
 
           g_strfreev (message);
-          g_free (freeme);
 
 	  notify_notification_show (notif, &error);
 
@@ -200,24 +140,24 @@ zenity_notification_handle_stdin (GIOCha
 	  }
 
 	  g_object_unref (notif);
-	} else {
-#else
-	{ /* this brace is for balance */
-#endif
- 	  g_warning ("Notification framework not available");
 	}
       } else if (!g_ascii_strcasecmp (command, "tooltip")) {
-        if (g_utf8_validate (value, -1, NULL)) {
-          gtk_status_icon_set_tooltip_text (status_icon, value);
-        } else {
+        if (!g_utf8_validate (value, -1, NULL)) {
           g_warning ("Invalid UTF-8 in input!");
-        }
-      } else if (!g_ascii_strcasecmp (command, "visible")) {
-        if (!g_ascii_strcasecmp (value, "false")) {
-          gtk_status_icon_set_visible (status_icon, FALSE);
         } else {
-          gtk_status_icon_set_visible (status_icon, TRUE);
+	  NotifyNotification *notif;
+
+          notif = notify_notification_new (value,
+                                           NULL,
+                                           icon_file);
+          notify_notification_show (notif, &error);
+          if (error) {
+            g_warning ("Error showing notification: %s", error->message);
+	    g_error_free (error);
+	  }
 	}
+      } else if (!g_ascii_strcasecmp (command, "visible")) {
+
       } else {
 	g_warning ("Unknown command '%s'", command);
       }
@@ -252,52 +192,49 @@ zenity_notification_listen_on_stdin (Zen
 void 
 zenity_notification (ZenityData *data, ZenityNotificationData *notification_data)
 {
-  status_icon = gtk_status_icon_new ();
-  g_signal_connect (status_icon, "size-changed",
-		    G_CALLBACK (zenity_notification_icon_size_changed_cb), data);
+  GError *error;
+  NotifyNotification *notification;
 
-  if (notification_data->notification_text) {
-    gtk_status_icon_set_tooltip_text (status_icon, notification_data->notification_text);
-  } else {
-    gtk_status_icon_set_tooltip_text (status_icon, _("Zenity notification"));
-  }
-
-  icon_file = g_strdup (data->window_icon);
-  icon_stock = zenity_util_stock_from_filename (data->window_icon);
-
-  /* Only set the stock icon here; if we're going to display a
-   * custom pixbuf we wait for the size-changed signal to load
-   * it at the right size.
-   */
-  if (icon_stock) {
-    gtk_status_icon_set_from_stock (status_icon, icon_stock);
-  }
-
-#ifdef HAVE_LIBNOTIFY
   /* create the notification widget */
   if (!notify_is_initted ()) {
     notify_init (_("Zenity notification"));
   }
-#endif
  
   if (notification_data->listen) {
     zenity_notification_listen_on_stdin (data);
   } else {
-    /* if we aren't listening for changes, then close on activate (left-click) */
-    g_signal_connect (status_icon, "activate",
-		      G_CALLBACK (zenity_notification_icon_activate_cb), data);
-  }
+    if (notification_data->notification_text == NULL) {
+      exit (1);
+    }
+
+    notification = notify_notification_new (notification_data->notification_text, NULL, data->window_icon);
+    if (notification == NULL) {
+      exit (1);
+    }
+
+    /* if we aren't listening for changes, then close on default action */
+    notify_notification_add_action (notification,
+                                    "default",
+                                    "Do Default Action",
+                                    (NotifyActionCallback) on_notification_default_action,
+                                    data,
+                                    NULL);
+
+    /* Show icon and wait */
+    error = NULL;
+    if (!notify_notification_show (notification, &error)) {
+      if (error != NULL) {
+        g_warning("Error showing notification: %s", error->message);
+        g_error_free (error);
+      }
+      exit (1);
+    }
 
-  /* Show icon and wait */
-  gtk_status_icon_set_visible (status_icon, TRUE);
+  }
 
   if(data->timeout_delay > 0) {
     g_timeout_add_seconds (data->timeout_delay, (GSourceFunc) zenity_util_timeout_handle, NULL);
   }
 
   gtk_main ();
-
-  /* Cleanup */
-  g_object_unref (status_icon);
-  g_free (icon_file);
 }
