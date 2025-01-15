$NetBSD: patch-Source_WebKit_UIProcess_API_glib_WebKitWebResource.cpp,v 1.1 2025/01/15 12:51:47 wiz Exp $

Fix build with gobject-introspection 1.82+.

--- Source/WebKit/UIProcess/API/glib/WebKitWebResource.cpp.orig	2025-01-15 11:57:43.112849372 +0000
+++ Source/WebKit/UIProcess/API/glib/WebKitWebResource.cpp
@@ -363,8 +363,8 @@ static void resourceDataCallback(API::Da
  * webkit_web_resource_get_data:
  * @resource: a #WebKitWebResource
  * @cancellable: (allow-none): a #GCancellable or %NULL to ignore
- * @callback: (scope async): a #GAsyncReadyCallback to call when the request is satisfied
- * @user_data: (closure): the data to pass to callback function
+ * @callback: (scope async) (closure user_data): a #GAsyncReadyCallback to call when the request is satisfied
+ * @user_data: the data to pass to callback function
  *
  * Asynchronously get the raw data for @resource.
  *
