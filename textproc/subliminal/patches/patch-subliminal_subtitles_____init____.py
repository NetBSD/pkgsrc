$NetBSD: patch-subliminal_subtitles_____init____.py,v 1.1 2017/04/14 14:17:45 leot Exp $

Use print() function from the __future__ in order to make the code compatible
with Python 3.

--- subliminal/subtitles/__init__.py.orig	2016-05-01 17:44:42.000000000 +0000
+++ subliminal/subtitles/__init__.py
@@ -1,4 +1,5 @@
 # -*- coding: utf-8 -*-
+from __future__ import print_function
 from datetime import time
 
 
@@ -85,4 +86,4 @@ class Cue(object):
 
 if __name__ == '__main__':
     cue = Cue(time(), time(1), [Bold('Hello')])
-    print repr(cue)
+    print(repr(cue))
