$NetBSD: patch-Source_WebKit_WebProcess_InjectedBundle_API_glib_WebKitWebPage.cpp,v 1.1 2025/01/15 12:51:47 wiz Exp $

Fix build with gobject-introspection 1.82+.

--- Source/WebKit/WebProcess/InjectedBundle/API/glib/WebKitWebPage.cpp.orig	2025-01-15 12:06:32.969957516 +0000
+++ Source/WebKit/WebProcess/InjectedBundle/API/glib/WebKitWebPage.cpp
@@ -871,8 +871,8 @@ WebKitWebEditor* webkit_web_page_get_edi
  * @web_page: a #WebKitWebPage
  * @message: a #WebKitUserMessage
  * @cancellable: (nullable): a #GCancellable or %NULL to ignore
- * @callback: (scope async): (nullable): A #GAsyncReadyCallback to call when the request is satisfied or %NULL
- * @user_data: (closure): the data to pass to callback function
+ * @callback: (scope async) (closure user_data): (nullable): A #GAsyncReadyCallback to call when the request is satisfied or %NULL
+ * @user_data: the data to pass to callback function
  *
  * Send @message to the #WebKitWebView corresponding to @web_page. If @message is floating, it's consumed.
  *
