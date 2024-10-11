$NetBSD: patch-third__party_libwebrtc_build_android_gyp_util_build__utils.py,v 1.1 2024/10/11 13:55:47 wiz Exp $

Fix build with Python 3.13.

--- third_party/libwebrtc/build/android/gyp/util/build_utils.py.orig	2024-10-11 13:43:32.145451522 +0000
+++ third_party/libwebrtc/build/android/gyp/util/build_utils.py
@@ -12,7 +12,7 @@ import fnmatch
 import json
 import logging
 import os
-import pipes
+import shlex
 import re
 import shutil
 import stat
@@ -199,7 +199,7 @@ class CalledProcessError(Exception):
     # A user should be able to simply copy and paste the command that failed
     # into their shell.
     copyable_command = '( cd {}; {} )'.format(os.path.abspath(self.cwd),
-        ' '.join(map(pipes.quote, self.args)))
+        ' '.join(map(shlex.quote, self.args)))
     return 'Command failed: {}\n{}'.format(copyable_command, self.output)
 
 
