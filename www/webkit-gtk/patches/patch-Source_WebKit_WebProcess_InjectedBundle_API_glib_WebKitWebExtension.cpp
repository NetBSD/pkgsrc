$NetBSD: patch-Source_WebKit_WebProcess_InjectedBundle_API_glib_WebKitWebExtension.cpp,v 1.1 2025/01/15 12:51:47 wiz Exp $

Fix build with gobject-introspection 1.82+.

--- Source/WebKit/WebProcess/InjectedBundle/API/glib/WebKitWebExtension.cpp.orig	2025-01-15 12:07:02.528235593 +0000
+++ Source/WebKit/WebProcess/InjectedBundle/API/glib/WebKitWebExtension.cpp
@@ -257,8 +257,8 @@ WebKitWebPage* webkit_web_extension_get_
  * @extension: a #WebKitWebExtension
  * @message: a #WebKitUserMessage
  * @cancellable: (nullable): a #GCancellable or %NULL to ignore
- * @callback: (scope async): (nullable): A #GAsyncReadyCallback to call when the request is satisfied or %NULL
- * @user_data: (closure): the data to pass to callback function
+ * @callback: (scope async) (closure user_data): (nullable): A #GAsyncReadyCallback to call when the request is satisfied or %NULL
+ * @user_data: the data to pass to callback function
  *
  * Send @message to the #WebKitWebContext corresponding to @extension. If @message is floating, it's consumed.
  *
