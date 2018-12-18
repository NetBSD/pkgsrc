$NetBSD: patch-src_plugins_platforms_xcb_qxcbconnection__basic.h,v 1.1 2018/12/18 09:57:18 adam Exp $

Fix building.

--- src/plugins/platforms/xcb/qxcbconnection_basic.h.orig	2018-12-13 14:45:57.605333077 +0000
+++ src/plugins/platforms/xcb/qxcbconnection_basic.h
@@ -157,7 +157,7 @@ private:
 #define Q_XCB_REPLY_CONNECTION_ARG(connection, ...) connection
 
 struct QStdFreeDeleter {
-    void operator()(void *p) const Q_DECL_NOTHROW { return std::free(p); }
+    void operator()(void *p) const Q_DECL_NOTHROW { return free(p); }
 };
 
 #define Q_XCB_REPLY(call, ...) \
