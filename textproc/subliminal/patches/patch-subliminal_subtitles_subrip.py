$NetBSD: patch-subliminal_subtitles_subrip.py,v 1.2 2017/04/14 19:10:23 leot Exp $

- Use print() function from the __future__ in order to make the code compatible
  with Python 3.
- Fix an indentation error.

--- subliminal/subtitles/subrip.py.orig	2016-06-24 19:30:34.000000000 +0000
+++ subliminal/subtitles/subrip.py
@@ -1,4 +1,5 @@
 # -*- coding: utf-8 -*-
+from __future__ import print_function
 import re
 from datetime import time
 
@@ -73,10 +74,10 @@ class SubripSubtitle(object):
 
 
 if __name__ == '__main__':
-    print read_cue('toto')
-      i = 0
+    print(read_cue('toto'))
+    i = 0
     for x in read_cue('toto'):
-        print x
+        print(x)
         if i > 10:
             break
         i += 1
