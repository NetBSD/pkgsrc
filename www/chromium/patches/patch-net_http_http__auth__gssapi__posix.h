$NetBSD: patch-net_http_http__auth__gssapi__posix.h,v 1.6 2025/09/08 13:24:28 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/http/http_auth_gssapi_posix.h.orig	2025-08-29 18:50:09.000000000 +0000
+++ net/http/http_auth_gssapi_posix.h
@@ -21,6 +21,9 @@
 #if BUILDFLAG(IS_APPLE)
 #include <GSS/gssapi.h>
 #elif BUILDFLAG(IS_FREEBSD)
+#ifndef GSS_C_DELEG_POLICY_FLAG
+#define GSS_C_DELEG_POLICY_FLAG 32768
+#endif
 #include <gssapi/gssapi.h>
 #else
 #include <gssapi.h>
