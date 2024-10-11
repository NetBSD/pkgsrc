$NetBSD: patch-testing_xpcshell_runxpcshelltests.py,v 1.1 2024/10/11 13:55:47 wiz Exp $

Fix build with Python 3.13.

--- testing/xpcshell/runxpcshelltests.py.orig	2024-10-11 13:42:14.137641240 +0000
+++ testing/xpcshell/runxpcshelltests.py
@@ -7,7 +7,7 @@
 import copy
 import json
 import os
-import pipes
+import shlex
 import platform
 import random
 import re
@@ -372,11 +372,11 @@ class XPCShellTestThread(Thread):
         )
         self.log.info("%s | environment: %s" % (name, list(changedEnv)))
         shell_command_tokens = [
-            pipes.quote(tok) for tok in list(changedEnv) + completeCmd
+            shlex.quote(tok) for tok in list(changedEnv) + completeCmd
         ]
         self.log.info(
             "%s | as shell command: (cd %s; %s)"
-            % (name, pipes.quote(testdir), " ".join(shell_command_tokens))
+            % (name, shlex.quote(testdir), " ".join(shell_command_tokens))
         )
 
     def killTimeout(self, proc):
