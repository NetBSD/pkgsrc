$NetBSD: patch-components_policy_tools_generate__policy__source.py,v 1.32 2026/11/08 15:39:01 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/policy/tools/generate_policy_source.py.orig	2026-11-02 23:22:33.000000000 +0000
+++ components/policy/tools/generate_policy_source.py
@@ -36,9 +36,9 @@ PLATFORM_STRINGS = {
   'ios': ['ios'],
   'fuchsia': ['fuchsia'],
   'chrome.win': ['win'],
-  'chrome.linux': ['linux'],
+  'chrome.linux': ['linux', 'openbsd', 'freebsd', 'netbsd'],
   'chrome.mac': ['mac'],
-  'chrome.*': ['win', 'mac', 'linux'],
+  'chrome.*': ['win', 'mac', 'linux', 'openbsd', 'freebsd', 'netbsd'],
   'chrome.win7': ['win'],
 }
 
