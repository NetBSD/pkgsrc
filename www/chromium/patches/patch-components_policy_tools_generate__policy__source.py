$NetBSD: patch-components_policy_tools_generate__policy__source.py,v 1.2 2025/05/16 16:08:23 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/policy/tools/generate_policy_source.py.orig	2025-05-05 19:21:24.000000000 +0000
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
 
