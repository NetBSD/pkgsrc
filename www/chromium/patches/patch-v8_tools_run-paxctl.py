$NetBSD: patch-v8_tools_run-paxctl.py,v 1.14 2026/01/19 16:14:24 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- v8/tools/run-paxctl.py.orig	2026-01-19 14:53:54.818980162 +0000
+++ v8/tools/run-paxctl.py
@@ -0,0 +1,16 @@
+#!@PYTHONBIN@
+# Copyright 2014 the V8 project authors. All rights reserved.
+# Use of this source code is governed by a BSD-style license that can be
+# found in the LICENSE file.
+
+"""This program wraps an arbitrary command since gn currently can only execute
+scripts."""
+
+import subprocess
+import sys
+import os
+
+with open(sys.argv[1], 'w'):
+  os.utime(sys.argv[1], None)
+
+sys.exit(subprocess.call(sys.argv[2:]))
