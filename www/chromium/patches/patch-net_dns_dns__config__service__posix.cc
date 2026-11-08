$NetBSD: patch-net_dns_dns__config__service__posix.cc,v 1.32 2026/11/08 15:39:06 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/dns/dns_config_service_posix.cc.orig	2026-11-02 23:22:33.000000000 +0000
+++ net/dns/dns_config_service_posix.cc
@@ -36,6 +36,11 @@
 #include "net/dns/dns_config_watcher_mac.h"
 #endif
 
+#if BUILDFLAG(IS_BSD)
+#include "base/command_line.h"
+#include "sandbox/policy/switches.h"
+#endif
+
 namespace net {
 
 namespace internal {
@@ -133,6 +138,13 @@ class DnsConfigServicePosix::Watcher : p
   bool Watch() override {
     CheckOnCorrectSequence();
 
+// pledge + unveil
+#if !BUILDFLAG(IS_NETBSD)
+    base::CommandLine* command_line = base::CommandLine::ForCurrentProcess();
+    if (!command_line->HasSwitch(sandbox::policy::switches::kNoSandbox))
+      return false;
+#endif
+
     bool success = true;
     if (!config_watcher_.Watch(base::BindRepeating(&Watcher::OnConfigChanged,
                                                    base::Unretained(this)))) {
