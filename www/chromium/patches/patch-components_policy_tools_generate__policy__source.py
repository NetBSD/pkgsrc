$NetBSD: patch-components_policy_tools_generate__policy__source.py,v 1.10 2025/11/20 08:36:13 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/policy/tools/generate_policy_source.py.orig	2025-11-14 20:31:45.000000000 +0000
+++ components/policy/tools/generate_policy_source.py
@@ -38,9 +38,9 @@ PLATFORM_STRINGS = {
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
 
