$NetBSD: patch-subliminal_subtitles_subrip.py,v 1.1 2017/04/14 14:17:45 leot Exp $

Use print() function from the __future__ in order to make the code compatible
with Python 3.

--- subliminal/subtitles/subrip.py.orig	2016-06-24 19:30:34.000000000 +0000
+++ subliminal/subtitles/subrip.py
@@ -1,5 +1,6 @@
 # -*- coding: utf-8 -*-
 import re
+from __future__ import print_function
 from datetime import time
 
 from subliminal.subtitles import Cue
@@ -73,10 +74,10 @@ class SubripSubtitle(object):
 
 
 if __name__ == '__main__':
-    print read_cue('toto')
+    print(read_cue('toto'))
       i = 0
     for x in read_cue('toto'):
-        print x
+        print(x)
         if i > 10:
             break
         i += 1
