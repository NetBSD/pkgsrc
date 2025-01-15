$NetBSD: patch-Source_WebKit_UIProcess_API_glib_WebKitWebsiteDataManager.cpp,v 1.1 2025/01/15 12:51:47 wiz Exp $

Fix build with gobject-introspection 1.82+.

--- Source/WebKit/UIProcess/API/glib/WebKitWebsiteDataManager.cpp.orig	2025-01-15 11:56:03.981338978 +0000
+++ Source/WebKit/UIProcess/API/glib/WebKitWebsiteDataManager.cpp
@@ -1013,8 +1013,8 @@ static OptionSet<WebsiteDataType> toWebs
  * @manager: a #WebKitWebsiteDataManager
  * @types: #WebKitWebsiteDataTypes
  * @cancellable: (allow-none): a #GCancellable or %NULL to ignore
- * @callback: (scope async): a #GAsyncReadyCallback to call when the request is satisfied
- * @user_data: (closure): the data to pass to callback function
+ * @callback: (scope async) (closure user_data): a #GAsyncReadyCallback to call when the request is satisfied
+ * @user_data: the data to pass to callback function
  *
  * Asynchronously get the list of #WebKitWebsiteData for the given @types.
  *
@@ -1068,8 +1068,8 @@ GList* webkit_website_data_manager_fetch
  * @types: #WebKitWebsiteDataTypes
  * @website_data: (element-type WebKitWebsiteData): a #GList of #WebKitWebsiteData
  * @cancellable: (allow-none): a #GCancellable or %NULL to ignore
- * @callback: (scope async): a #GAsyncReadyCallback to call when the request is satisfied
- * @user_data: (closure): the data to pass to callback function
+ * @callback: (scope async) (closure user_data): a #GAsyncReadyCallback to call when the request is satisfied
+ * @user_data: the data to pass to callback function
  *
  * Asynchronously removes the website data of the for the given @types for websites in the given @website_data list.
  * Use webkit_website_data_manager_clear() if you want to remove the website data for all sites.
@@ -1133,8 +1133,8 @@ gboolean webkit_website_data_manager_rem
  * @types: #WebKitWebsiteDataTypes
  * @timespan: a #GTimeSpan
  * @cancellable: (allow-none): a #GCancellable or %NULL to ignore
- * @callback: (scope async): a #GAsyncReadyCallback to call when the request is satisfied
- * @user_data: (closure): the data to pass to callback function
+ * @callback: (scope async) (closure user_data): a #GAsyncReadyCallback to call when the request is satisfied
+ * @user_data: the data to pass to callback function
  *
  * Asynchronously clear the website data of the given @types modified in the past @timespan.
  * If @timespan is 0, all website data will be removed.
@@ -1427,8 +1427,8 @@ GList* webkit_itp_third_party_get_first_
  * webkit_website_data_manager_get_itp_summary:
  * @manager: a #WebKitWebsiteDataManager
  * @cancellable: (allow-none): a #GCancellable or %NULL to ignore
- * @callback: (scope async): a #GAsyncReadyCallback to call when the request is satisfied
- * @user_data: (closure): the data to pass to callback function
+ * @callback: (scope async) (closure user_data): a #GAsyncReadyCallback to call when the request is satisfied
+ * @user_data: the data to pass to callback function
  *
  * Asynchronously get the list of #WebKitITPThirdParty seen for @manager. Every #WebKitITPThirdParty
  * contains the list of #WebKitITPFirstParty under which it has been seen.
