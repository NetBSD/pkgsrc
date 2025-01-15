$NetBSD: patch-Source_JavaScriptCore_API_glib_JSCContext.cpp,v 1.1 2025/01/15 12:51:47 wiz Exp $

Fix build with gobject-introspection 1.82+.

--- Source/JavaScriptCore/API/glib/JSCContext.cpp.orig	2025-01-15 11:27:24.431489728 +0000
+++ Source/JavaScriptCore/API/glib/JSCContext.cpp
@@ -767,8 +767,8 @@ void jsc_context_clear_exception(JSCCont
 /**
  * jsc_context_push_exception_handler:
  * @context: a #JSCContext
- * @handler: a #JSCExceptionHandler
- * @user_data: (closure): user data to pass to @handler
+ * @handler: (closure user_data): a #JSCExceptionHandler
+ * @user_data: user data to pass to @handler
  * @destroy_notify: (nullable): destroy notifier for @user_data
  *
  * Push an exception handler in @context. Whenever a JavaScript exception happens in
