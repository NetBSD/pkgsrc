$NetBSD: patch-Source_WebKit_UIProcess_API_glib_WebKitUserContentFilterStore.cpp,v 1.1 2025/01/15 12:51:47 wiz Exp $

Fix build with gobject-introspection 1.82+.

--- Source/WebKit/UIProcess/API/glib/WebKitUserContentFilterStore.cpp.orig	2025-01-15 12:00:10.184519644 +0000
+++ Source/WebKit/UIProcess/API/glib/WebKitUserContentFilterStore.cpp
@@ -205,8 +205,8 @@ static void webkitUserContentFilterStore
  * @identifier: a string used to identify the saved filter
  * @source: #GBytes containing the rule set in JSON format
  * @cancellable: (allow-none): a #GCancellable or %NULL to ignore
- * @callback: (scope async): a #GAsyncReadyCallback to call when saving is completed
- * @user_data: (closure): the data to pass to the callback function
+ * @callback: (scope async) (closure user_data): a #GAsyncReadyCallback to call when saving is completed
+ * @user_data: the data to pass to the callback function
  *
  * Asynchronously save a content filter from a source rule set in the
  * [WebKit content extesions JSON format](https://webkit.org/blog/3476/content-blockers-first-look/).
@@ -263,8 +263,8 @@ WEBKIT_DEFINE_ASYNC_DATA_STRUCT(SaveTask
  * @identifier: a string used to identify the saved filter
  * @file: a #GFile containing the rule set in JSON format
  * @cancellable: (allow-none): a #GCancellable or %NULL to ignore
- * @callback: (scope async): a #GAsyncReadyCallback to call when saving is completed
- * @user_data: (closure): the data to pass to the callback function
+ * @callback: (scope async) (closure user_data): a #GAsyncReadyCallback to call when saving is completed
+ * @user_data: the data to pass to the callback function
  *
  * Asynchronously save a content filter from the contents of a file, which must be
  * native to the platform, as checked by g_file_is_native(). See
@@ -341,8 +341,8 @@ WebKitUserContentFilter* webkit_user_con
  * @store: a #WebKitUserContentFilterStore
  * @identifier: a filter identifier
  * @cancellable: (allow-none): a #GCancellable or %NULL to ignore
- * @callback: (scope async): a #GAsyncReadyCallback to call when the removal is completed
- * @user_data: (closure): the data to pass to the callback function
+ * @callback: (scope async) (closure user_data): a #GAsyncReadyCallback to call when the removal is completed
+ * @user_data: the data to pass to the callback function
  *
  * Asynchronously remove a content filter given its @identifier.
  *
@@ -396,8 +396,8 @@ gboolean webkit_user_content_filter_stor
  * @store: a #WebKitUserContentFilterStore
  * @identifier: a filter identifier
  * @cancellable: (allow-none): a #GCancellable or %NULL to ignore
- * @callback: (scope async): a #GAsyncReadyCallback to call when the load is completed
- * @user_data: (closure): the data to pass to the callback function
+ * @callback: (scope async) (closure user_data): a #GAsyncReadyCallback to call when the load is completed
+ * @user_data: the data to pass to the callback function
  *
  * Asynchronously load a content filter given its @identifier. The filter must have been
  * previously stored using webkit_user_content_filter_store_save().
@@ -451,8 +451,8 @@ WebKitUserContentFilter* webkit_user_con
  * webkit_user_content_filter_store_fetch_identifiers:
  * @store: a #WebKitUserContentFilterStore
  * @cancellable: (allow-none): a #GCancellable or %NULL to ignore
- * @callback: (scope async): a #GAsyncReadyCallback to call when the removal is completed
- * @user_data: (closure): the data to pass to the callback function
+ * @callback: (scope async) (closure user_data): a #GAsyncReadyCallback to call when the removal is completed
+ * @user_data: the data to pass to the callback function
  *
  * Asynchronously retrieve a list of the identifiers for all the stored filters.
  *
