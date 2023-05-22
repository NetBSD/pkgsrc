$NetBSD: patch-src_libproxy_proxy.h,v 1.1 2023/05/22 20:28:28 wiz Exp $

Fix C++ usage of header.
https://github.com/libproxy/libproxy/issues/226

Fix Use glib-object header instead of gio
https://github.com/libproxy/libproxy/issues/230

--- src/libproxy/proxy.h.orig	2023-05-15 13:09:42.000000000 +0000
+++ src/libproxy/proxy.h
@@ -22,12 +22,12 @@
 
 #pragma once
 
+#include <glib-object.h>
+
 #ifdef __cplusplus
 extern "C" {
 #endif
 
-#include <gio/gio.h>
-
 /**
  * SECTION:px-proxy
  * @short_description: A convient helper for using proxy servers
