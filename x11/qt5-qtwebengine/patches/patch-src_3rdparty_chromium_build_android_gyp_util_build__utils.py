$NetBSD: patch-src_3rdparty_chromium_build_android_gyp_util_build__utils.py,v 1.1 2025/07/07 13:50:43 wiz Exp $

Python 3.13 fix
https://sources.debian.org/data/main/q/qtwebengine-opensource-src/5.15.18+dfsg-2~bpo12+1/debian/patches/python3.13-pipes.patch

--- src/3rdparty/chromium/build/android/gyp/util/build_utils.py.orig	2024-04-03 09:31:09.000000000 +0000
+++ src/3rdparty/chromium/build/android/gyp/util/build_utils.py
@@ -12,8 +12,8 @@ import fnmatch
 import json
 import logging
 import os
-import pipes
 import re
+import shlex
 import shutil
 import stat
 import subprocess
@@ -197,8 +197,9 @@ class CalledProcessError(Exception):
   def __str__(self):
     # A user should be able to simply copy and paste the command that failed
     # into their shell.
+    printed_cmd = shlex.join(self.args)
     copyable_command = '( cd {}; {} )'.format(os.path.abspath(self.cwd),
-        ' '.join(map(pipes.quote, self.args)))
+                                              printed_cmd)
     return 'Command failed: {}\n{}'.format(copyable_command, self.output)
 
 
