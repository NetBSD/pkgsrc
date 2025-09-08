$NetBSD: patch-components_policy_core_common_policy__paths.cc,v 1.6 2025/09/08 13:24:24 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/policy/core/common/policy_paths.cc.orig	2025-08-29 18:50:09.000000000 +0000
+++ components/policy/core/common/policy_paths.cc
@@ -17,6 +17,10 @@ namespace policy {
 const char kPolicyPath[] = "/etc/opt/chrome/policies";
 #elif BUILDFLAG(GOOGLE_CHROME_FOR_TESTING_BRANDING)
 const char kPolicyPath[] = "/etc/opt/chrome_for_testing/policies";
+#elif BUILDFLAG(IS_FREEBSD)
+const char kPolicyPath[] = "/usr/local/etc/chromium/policies";
+#elif BUILDFLAG(IS_NETBSD)
+const char kPolicyPath[] = "@PKG_SYSCONFBASE@/chromium/policies";
 #else
 const char kPolicyPath[] = "/etc/chromium/policies";
 #endif  // BUILDFLAG(GOOGLE_CHROME_BRANDING)
