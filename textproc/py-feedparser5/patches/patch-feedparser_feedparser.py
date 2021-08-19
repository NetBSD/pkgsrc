$NetBSD: patch-feedparser_feedparser.py,v 1.1 2021/08/19 19:21:00 nia Exp $

Fix compatibility with Python 3.9.

Backported from:
https://github.com/kurtmckee/feedparser/pull/206
https://bugzilla.redhat.com/show_bug.cgi?id=1807186

--- feedparser/feedparser.py.orig	2015-07-24 05:00:04.000000000 +0000
+++ feedparser/feedparser.py
@@ -90,7 +90,10 @@ except ImportError:
     base64 = binascii = None
 else:
     # Python 3.1 deprecates decodestring in favor of decodebytes
-    _base64decode = getattr(base64, 'decodebytes', base64.decodestring)
+    try:
+        _base64decode = base64.decodebytes
+    except AttributeError:
+        _base64decode = base64.decodestring
 
 # _s2bytes: convert a UTF-8 str to bytes if the interpreter is Python 3
 # _l2bytes: convert a list of ints to bytes if the interpreter is Python 3
