$NetBSD: patch-Source_WebKit_UIProcess_API_glib_WebKitFaviconDatabase.cpp,v 1.1 2025/01/15 12:51:47 wiz Exp $

Fix build with gobject-introspection 1.82+.

--- Source/WebKit/UIProcess/API/glib/WebKitFaviconDatabase.cpp.orig	2025-01-15 11:55:33.168182647 +0000
+++ Source/WebKit/UIProcess/API/glib/WebKitFaviconDatabase.cpp
@@ -197,9 +197,9 @@ void webkitFaviconDatabaseGetFaviconInte
  * @database: a #WebKitFaviconDatabase
  * @page_uri: URI of the page for which we want to retrieve the favicon
  * @cancellable: (allow-none): A #GCancellable or %NULL.
- * @callback: (scope async): A #GAsyncReadyCallback to call when the request is
+ * @callback: (scope async) (closure user_data): A #GAsyncReadyCallback to call when the request is
  *            satisfied or %NULL if you don't care about the result.
- * @user_data: (closure): The data to pass to @callback.
+ * @user_data: The data to pass to @callback.
  *
  * Asynchronously obtains a #cairo_surface_t of the favicon for the
  * given page URI. It returns the cached icon if it's in the database
