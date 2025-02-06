$NetBSD: patch-net_dns_dns__config__service__posix.cc,v 1.1 2025/02/06 09:58:15 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/dns/dns_config_service_posix.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ net/dns/dns_config_service_posix.cc
@@ -39,6 +39,11 @@
 #include "net/dns/dns_config_watcher_mac.h"
 #endif
 
+#if BUILDFLAG(IS_BSD)
+#include "base/command_line.h"
+#include "sandbox/policy/switches.h"
+#endif
+
 namespace net {
 
 namespace internal {
@@ -136,6 +141,11 @@ class DnsConfigServicePosix::Watcher : p
   bool Watch() override {
     CheckOnCorrectSequence();
 
+// pledge + unveil
+    base::CommandLine* command_line = base::CommandLine::ForCurrentProcess();
+    if (!command_line->HasSwitch(sandbox::policy::switches::kNoSandbox))
+      return false;
+
     bool success = true;
     if (!config_watcher_.Watch(base::BindRepeating(&Watcher::OnConfigChanged,
                                                    base::Unretained(this)))) {
