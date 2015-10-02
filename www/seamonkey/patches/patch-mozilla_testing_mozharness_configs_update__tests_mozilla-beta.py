$NetBSD: patch-mozilla_testing_mozharness_configs_update__tests_mozilla-beta.py,v 1.1 2015/10/02 22:49:36 ryoon Exp $

--- mozilla/testing/mozharness/configs/update_tests/mozilla-beta.py.orig	2015-09-29 15:44:15.000000000 +0000
+++ mozilla/testing/mozharness/configs/update_tests/mozilla-beta.py
@@ -0,0 +1,18 @@
+from mozharness.base.script import platform_name
+
+PLATFORM_CONFIG = {
+    'linux64': {
+        'update_verify_config': 'mozBeta-firefox-linux64.cfg'
+    },
+    'macosx': {
+        'update_verify_config': 'mozBeta-firefox-mac64.cfg'
+    },
+    'win32': {
+        'update_verify_config': 'mozBeta-firefox-win32.cfg'
+    },
+}
+
+config = PLATFORM_CONFIG[platform_name()]
+config.update({
+    'firefox_ui_branch': 'mozilla-beta'
+})
