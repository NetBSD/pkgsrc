$NetBSD: patch-img.py,v 1.1 2016/01/17 14:22:11 wiz Exp $

Fix for code-injection vulnerability (CVE-2015-8557) from upstream.

The following patch includes changes made by commits 6b4baae, 0036ab1,
3982887, and 91624f2. Avoid the shell entirely when finding fonts, and
misc bug fixes.

See more details:
https://bitbucket.org/birkenfeld/pygments-main/history-node/e0bf451e64fd/pygments/formatters/img.py

--- pygments/formatters/img.py.orig	2016-01-17 02:49:19.000000000 +0900
+++ pygments/formatters/img.py	2016-01-17 02:49:23.000000000 +0900
@@ -5,7 +5,7 @@
 
     Formatter for Pixmap output.
 
-    :copyright: Copyright 2006-2014 by the Pygments team, see AUTHORS.
+    :copyright: Copyright 2006-2015 by the Pygments team, see AUTHORS.
     :license: BSD, see LICENSE for details.
 """
 
@@ -15,6 +15,8 @@
 from pygments.util import get_bool_opt, get_int_opt, get_list_opt, \
     get_choice_opt, xrange
 
+import subprocess
+
 # Import this carefully
 try:
     from PIL import Image, ImageDraw, ImageFont
@@ -75,16 +77,13 @@
             self._create_nix()
 
     def _get_nix_font_path(self, name, style):
-        try:
-            from commands import getstatusoutput
-        except ImportError:
-            from subprocess import getstatusoutput
-        exit, out = getstatusoutput('fc-list "%s:style=%s" file' %
-                                    (name, style))
-        if not exit:
-            lines = out.splitlines()
+        proc = subprocess.Popen(['fc-list', "%s:style=%s" % (name, style), 'file'],
+                                stdout=subprocess.PIPE, stderr=None)
+        stdout, _ = proc.communicate()
+        if proc.returncode == 0:
+            lines = stdout.splitlines()
             if lines:
-                path = lines[0].strip().strip(':')
+                path = lines[0].decode().strip().strip(':')
                 return path
 
     def _create_nix(self):
@@ -197,7 +196,7 @@
         bold and italic fonts will be generated.  This really should be a
         monospace font to look sane.
 
-        Default: "Bitstream Vera Sans Mono"
+        Default: "Bitstream Vera Sans Mono" on Windows, Courier New on \*nix
 
     `font_size`
         The font size in points to be used.
