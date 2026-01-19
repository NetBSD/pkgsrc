$NetBSD: patch-components_policy_core_common_cloud_cloud__policy__util.cc,v 1.14 2026/01/19 16:14:13 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/policy/core/common/cloud/cloud_policy_util.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ components/policy/core/common/cloud/cloud_policy_util.cc
@@ -21,7 +21,7 @@
 #include "base/win/wincred_shim.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 #include <pwd.h>
 #include <sys/types.h>
 #include <unistd.h>
@@ -36,10 +36,15 @@
 #import <SystemConfiguration/SCDynamicStoreCopySpecific.h>
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <limits.h>  // For HOST_NAME_MAX
 #endif
 
+#if BUILDFLAG(IS_FREEBSD) || BUILDFLAG(IS_NETBSD)
+#include <sys/param.h>
+#define HOST_NAME_MAX MAXHOSTNAMELEN
+#endif
+
 #include <algorithm>
 #include <utility>
 
@@ -84,7 +89,7 @@ namespace policy {
 namespace em = enterprise_management;
 
 std::string GetMachineName() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   char hostname[HOST_NAME_MAX];
   if (gethostname(hostname, HOST_NAME_MAX) == 0)  // Success.
     return hostname;
@@ -140,7 +145,7 @@ std::string GetMachineName() {
 
 std::string GetOSVersion() {
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_APPLE) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   return base::SysInfo::OperatingSystemVersion();
 #elif BUILDFLAG(IS_WIN)
   base::win::OSInfo::VersionNumber version_number =
@@ -162,7 +167,7 @@ std::string GetOSArchitecture() {
 }
 
 std::string GetOSUsername() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_APPLE)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD)
   struct passwd* creds = getpwuid(getuid());
   if (!creds || !creds->pw_name)
     return std::string();
