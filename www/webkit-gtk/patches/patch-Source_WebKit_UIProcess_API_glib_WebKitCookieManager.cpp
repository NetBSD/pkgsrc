$NetBSD: patch-Source_WebKit_UIProcess_API_glib_WebKitCookieManager.cpp,v 1.1 2025/01/15 12:51:47 wiz Exp $

Fix build with gobject-introspection 1.82+.

--- Source/WebKit/UIProcess/API/glib/WebKitCookieManager.cpp.orig	2025-01-15 11:54:20.049054789 +0000
+++ Source/WebKit/UIProcess/API/glib/WebKitCookieManager.cpp
@@ -221,8 +221,8 @@ void webkit_cookie_manager_set_accept_po
  * webkit_cookie_manager_get_accept_policy:
  * @cookie_manager: a #WebKitCookieManager
  * @cancellable: (allow-none): a #GCancellable or %NULL to ignore
- * @callback: (scope async): a #GAsyncReadyCallback to call when the request is satisfied
- * @user_data: (closure): the data to pass to callback function
+ * @callback: (scope async) (closure user_data): a #GAsyncReadyCallback to call when the request is satisfied
+ * @user_data: the data to pass to callback function
  *
  * Asynchronously get the cookie acceptance policy of @cookie_manager.
  * Note that when policy was set to %WEBKIT_COOKIE_POLICY_ACCEPT_NO_THIRD_PARTY and
@@ -267,8 +267,8 @@ WebKitCookieAcceptPolicy webkit_cookie_m
  * @cookie_manager: a #WebKitCookieManager
  * @cookie: the #SoupCookie to be added
  * @cancellable: (allow-none): a #GCancellable or %NULL to ignore
- * @callback: (scope async): a #GAsyncReadyCallback to call when the request is satisfied
- * @user_data: (closure): the data to pass to callback function
+ * @callback: (scope async) (closure user_data): a #GAsyncReadyCallback to call when the request is satisfied
+ * @user_data: the data to pass to callback function
  *
  * Asynchronously add a #SoupCookie to the underlying storage.
  *
@@ -313,8 +313,8 @@ gboolean webkit_cookie_manager_add_cooki
  * @cookie_manager: a #WebKitCookieManager
  * @uri: the URI associated to the cookies to be retrieved
  * @cancellable: (allow-none): a #GCancellable or %NULL to ignore
- * @callback: (scope async): a #GAsyncReadyCallback to call when the request is satisfied
- * @user_data: (closure): the data to pass to callback function
+ * @callback: (scope async) (closure user_data): a #GAsyncReadyCallback to call when the request is satisfied
+ * @user_data: the data to pass to callback function
  *
  * Asynchronously get a list of #SoupCookie from @cookie_manager associated with @uri, which
  * must be either an HTTP or an HTTPS URL.
@@ -368,8 +368,8 @@ GList* webkit_cookie_manager_get_cookies
  * @cookie_manager: a #WebKitCookieManager
  * @cookie: the #SoupCookie to be deleted
  * @cancellable: (allow-none): a #GCancellable or %NULL to ignore
- * @callback: (scope async): a #GAsyncReadyCallback to call when the request is satisfied
- * @user_data: (closure): the data to pass to callback function
+ * @callback: (scope async) (closure user_data): a #GAsyncReadyCallback to call when the request is satisfied
+ * @user_data: the data to pass to callback function
  *
  * Asynchronously delete a #SoupCookie from the current session.
  *
@@ -414,8 +414,8 @@ gboolean webkit_cookie_manager_delete_co
  * webkit_cookie_manager_get_domains_with_cookies:
  * @cookie_manager: a #WebKitCookieManager
  * @cancellable: (allow-none): a #GCancellable or %NULL to ignore
- * @callback: (scope async): a #GAsyncReadyCallback to call when the request is satisfied
- * @user_data: (closure): the data to pass to callback function
+ * @callback: (scope async) (closure user_data): a #GAsyncReadyCallback to call when the request is satisfied
+ * @user_data: the data to pass to callback function
  *
  * Asynchronously get the list of domains for which @cookie_manager contains cookies.
  *
