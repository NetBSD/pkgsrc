$NetBSD: patch-Source_WebKit_WebProcess_InjectedBundle_API_gtk_DOM_WebKitDOMEventTarget.h,v 1.1 2025/01/15 12:51:47 wiz Exp $

Work around incompatibility with gobject-introspection 1.82+.

--- Source/WebKit/WebProcess/InjectedBundle/API/gtk/DOM/WebKitDOMEventTarget.h.orig	2025-01-15 12:07:24.113544284 +0000
+++ Source/WebKit/WebProcess/InjectedBundle/API/gtk/DOM/WebKitDOMEventTarget.h
@@ -89,22 +89,6 @@ WEBKIT_DEPRECATED gboolean  webkit_dom_e
                                                                 gpointer              user_data);
 
 /**
- * webkit_dom_event_target_remove_event_listener:
- * @target: A #WebKitDOMEventTarget
- * @event_name: A #gchar
- * @handler: (scope call): A #GCallback
- * @use_capture: A #gboolean
- *
- * Returns: a #gboolean
- *
- * Deprecated: 2.22: Use JavaScriptCore API instead
- */
-WEBKIT_DEPRECATED gboolean  webkit_dom_event_target_remove_event_listener(WebKitDOMEventTarget *target,
-                                                                   const char           *event_name,
-                                                                   GCallback             handler,
-                                                                   gboolean              use_capture);
-
-/**
  * webkit_dom_event_target_add_event_listener_with_closure: (rename-to webkit_dom_event_target_add_event_listener)
  * @target: A #WebKitDOMEventTarget
  * @event_name: A #gchar
@@ -124,7 +108,7 @@ WEBKIT_DEPRECATED gboolean webkit_dom_ev
                                                                             gboolean              use_capture);
 
 /**
- * webkit_dom_event_target_remove_event_listener_with_closure: (rename-to webkit_dom_event_target_remove_event_listener)
+ * webkit_dom_event_target_remove_event_listener_with_closure:
  * @target: A #WebKitDOMEventTarget
  * @event_name: A #gchar
  * @handler: A #GClosure
