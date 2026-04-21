$NetBSD: patch-components_policy_tools_generate__policy__source.py,v 1.18 2026/04/21 15:21:14 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/policy/tools/generate_policy_source.py.orig	2026-04-14 23:31:37.000000000 +0200
+++ components/policy/tools/generate_policy_source.py
@@ -37,9 +37,9 @@ PLATFORM_STRINGS = {
     'ios': ['ios'],
     'fuchsia': ['fuchsia'],
     'chrome.win': ['win'],
-    'chrome.linux': ['linux'],
+    'chrome.linux': ['linux', 'openbsd', 'freebsd', 'netbsd'],
     'chrome.mac': ['mac'],
-    'chrome.*': ['win', 'mac', 'linux'],
+    'chrome.*': ['win', 'mac', 'linux', 'openbsd', 'freebsd', 'netbsd'],
     'chrome.win7': ['win'],
 }
 
