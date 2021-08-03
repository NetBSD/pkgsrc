$NetBSD: patch-src_3rdparty_chromium_net_http_http__auth__gssapi__posix.h,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/net/http/http_auth_gssapi_posix.h.orig	2020-07-15 18:56:00.000000000 +0000
+++ src/3rdparty/chromium/net/http/http_auth_gssapi_posix.h
@@ -25,6 +25,10 @@
 #include <gssapi.h>
 #endif
 
+#ifndef GSS_C_DELEG_POLICY_FLAG
+#define GSS_C_DELEG_POLICY_FLAG 32768
+#endif
+
 namespace net {
 
 class HttpAuthChallengeTokenizer;
