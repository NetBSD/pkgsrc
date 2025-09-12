$NetBSD: patch-services_network_network__sandbox__hook__linux.h,v 1.7 2025/09/12 16:02:33 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/network/network_sandbox_hook_linux.h.orig	2025-09-08 23:21:33.000000000 +0000
+++ services/network/network_sandbox_hook_linux.h
@@ -6,7 +6,11 @@
 #define SERVICES_NETWORK_NETWORK_SANDBOX_HOOK_LINUX_H_
 
 #include "base/component_export.h"
+#if defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__)
+#include "sandbox/policy/sandbox.h"
+#else
 #include "sandbox/policy/linux/sandbox_linux.h"
+#endif
 
 namespace network {
 
