$NetBSD: patch-src_backend_plugins_pacrunner-duktape_pacrunner-duktape.c,v 1.1 2023/05/22 20:28:28 wiz Exp $

Fix build on NetBSD
https://github.com/libproxy/libproxy/issues/219

--- src/backend/plugins/pacrunner-duktape/pacrunner-duktape.c.orig	2023-05-15 13:09:42.000000000 +0000
+++ src/backend/plugins/pacrunner-duktape/pacrunner-duktape.c
@@ -28,6 +28,8 @@
 #include <netdb.h>
 #endif
 
+#include <netinet/in.h>                                                                                                                                                                                                       
+
 #include "pacrunner-duktape.h"
 #include "pacutils.h"
 #include "px-plugin-pacrunner.h"
