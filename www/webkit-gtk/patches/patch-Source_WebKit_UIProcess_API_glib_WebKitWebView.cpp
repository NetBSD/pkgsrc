$NetBSD: patch-Source_WebKit_UIProcess_API_glib_WebKitWebView.cpp,v 1.1 2025/01/15 12:51:47 wiz Exp $

Fix build with gobject-introspection 1.82+.

--- Source/WebKit/UIProcess/API/glib/WebKitWebView.cpp.orig	2025-01-15 11:58:07.472124794 +0000
+++ Source/WebKit/UIProcess/API/glib/WebKitWebView.cpp
@@ -3778,8 +3778,8 @@ gdouble webkit_web_view_get_zoom_level(W
  * @web_view: a #WebKitWebView
  * @command: the command to check
  * @cancellable: (allow-none): a #GCancellable or %NULL to ignore
- * @callback: (scope async): a #GAsyncReadyCallback to call when the request is satisfied
- * @user_data: (closure): the data to pass to callback function
+ * @callback: (scope async) (closure user_data): a #GAsyncReadyCallback to call when the request is satisfied
+ * @user_data: the data to pass to callback function
  *
  * Asynchronously check if it is possible to execute the given editing command.
  *
@@ -3952,8 +3952,8 @@ void webkitWebViewRunJavascriptWithoutFo
  * @web_view: a #WebKitWebView
  * @script: the script to run
  * @cancellable: (allow-none): a #GCancellable or %NULL to ignore
- * @callback: (scope async): a #GAsyncReadyCallback to call when the script finished
- * @user_data: (closure): the data to pass to callback function
+ * @callback: (scope async) (closure user_data): a #GAsyncReadyCallback to call when the script finished
+ * @user_data: the data to pass to callback function
  *
  * Asynchronously run @script in the context of the current page in @web_view. If
  * WebKitSettings:enable-javascript is FALSE, this method will do nothing.
@@ -4045,8 +4045,8 @@ WebKitJavascriptResult* webkit_web_view_
  * @script: the script to run
  * @world_name: the name of a #WebKitScriptWorld
  * @cancellable: (allow-none): a #GCancellable or %NULL to ignore
- * @callback: (scope async): a #GAsyncReadyCallback to call when the script finished
- * @user_data: (closure): the data to pass to callback function
+ * @callback: (scope async) (closure user_data): a #GAsyncReadyCallback to call when the script finished
+ * @user_data: the data to pass to callback function
  *
  * Asynchronously run @script in the script world with name @world_name of the current page context in @web_view.
  * If WebKitSettings:enable-javascript is FALSE, this method will do nothing.
@@ -4126,8 +4126,8 @@ static void resourcesStreamReadCallback(
  * @web_view: a #WebKitWebView
  * @resource: the location of the resource to load
  * @cancellable: (allow-none): a #GCancellable or %NULL to ignore
- * @callback: (scope async): a #GAsyncReadyCallback to call when the script finished
- * @user_data: (closure): the data to pass to callback function
+ * @callback: (scope async) (closure user_data): a #GAsyncReadyCallback to call when the script finished
+ * @user_data: the data to pass to callback function
  *
  * Asynchronously run the script from @resource in the context of the
  * current page in @web_view.
@@ -4276,8 +4276,8 @@ static void getContentsAsMHTMLDataCallba
  * @web_view: a #WebKitWebView
  * @save_mode: the #WebKitSaveMode specifying how the web page should be saved.
  * @cancellable: (allow-none): a #GCancellable or %NULL to ignore
- * @callback: (scope async): a #GAsyncReadyCallback to call when the request is satisfied
- * @user_data: (closure): the data to pass to callback function
+ * @callback: (scope async) (closure user_data): a #GAsyncReadyCallback to call when the request is satisfied
+ * @user_data: the data to pass to callback function
  *
  * Asynchronously save the current web page associated to the
  * #WebKitWebView into a self-contained format using the mode
@@ -4337,8 +4337,8 @@ GInputStream* webkit_web_view_save_finis
  * @file: the #GFile where the current web page should be saved to.
  * @save_mode: the #WebKitSaveMode specifying how the web page should be saved.
  * @cancellable: (allow-none): a #GCancellable or %NULL to ignore
- * @callback: (scope async): a #GAsyncReadyCallback to call when the request is satisfied
- * @user_data: (closure): the data to pass to callback function
+ * @callback: (scope async) (closure user_data): a #GAsyncReadyCallback to call when the request is satisfied
+ * @user_data: the data to pass to callback function
  *
  * Asynchronously save the current web page associated to the
  * #WebKitWebView into a self-contained format using the mode
@@ -4499,8 +4499,8 @@ static inline uint64_t generateSnapshotC
  * @region: the #WebKitSnapshotRegion for this snapshot
  * @options: #WebKitSnapshotOptions for the snapshot
  * @cancellable: (allow-none): a #GCancellable
- * @callback: (scope async): a #GAsyncReadyCallback
- * @user_data: (closure): user data
+ * @callback: (scope async) (closure user_data): a #GAsyncReadyCallback
+ * @user_data: user data
  *
  * Asynchronously retrieves a snapshot of @web_view for @region.
  * @options specifies how the snapshot should be rendered.
@@ -4666,8 +4666,8 @@ void webkit_web_view_restore_session_sta
 /**
  * webkit_web_view_add_frame_displayed_callback:
  * @web_view: a #WebKitWebView
- * @callback: a #WebKitFrameDisplayedCallback
- * @user_data: (closure): user data to pass to @callback
+ * @callback: (closure user_data): a #WebKitFrameDisplayedCallback
+ * @user_data: user data to pass to @callback
  * @destroy_notify: (nullable): destroy notifier for @user_data
  *
  * Add a callback to be called when the backend notifies that a frame has been displayed in @web_view.
@@ -4719,8 +4719,8 @@ void webkit_web_view_remove_frame_displa
  * @web_view: a #WebKitWebView
  * @message: a #WebKitUserMessage
  * @cancellable: (nullable): a #GCancellable or %NULL to ignore
- * @callback: (scope async): (nullable): A #GAsyncReadyCallback to call when the request is satisfied or %NULL
- * @user_data: (closure): the data to pass to callback function
+ * @callback: (scope async) (closure user_data): (nullable): A #GAsyncReadyCallback to call when the request is satisfied or %NULL
+ * @user_data: the data to pass to callback function
  *
  * Send @message to the #WebKitWebPage corresponding to @web_view. If @message is floating, it's consumed.
  *
