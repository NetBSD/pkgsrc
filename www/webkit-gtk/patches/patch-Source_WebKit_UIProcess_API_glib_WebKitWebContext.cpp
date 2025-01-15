$NetBSD: patch-Source_WebKit_UIProcess_API_glib_WebKitWebContext.cpp,v 1.1 2025/01/15 12:51:47 wiz Exp $

Fix build with gobject-introspection 1.82+.

--- Source/WebKit/UIProcess/API/glib/WebKitWebContext.cpp.orig	2025-01-15 11:57:15.646560534 +0000
+++ Source/WebKit/UIProcess/API/glib/WebKitWebContext.cpp
@@ -1159,8 +1159,8 @@ void webkit_web_context_set_additional_p
  * webkit_web_context_get_plugins:
  * @context: a #WebKitWebContext
  * @cancellable: (allow-none): a #GCancellable or %NULL to ignore
- * @callback: (scope async): a #GAsyncReadyCallback to call when the request is satisfied
- * @user_data: (closure): the data to pass to callback function
+ * @callback: (scope async) (closure user_data): a #GAsyncReadyCallback to call when the request is satisfied
+ * @user_data: the data to pass to callback function
  *
  * Asynchronously get the list of installed plugins.
  *
