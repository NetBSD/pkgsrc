$NetBSD: patch-firefox__decrypt.py,v 1.1 2020/06/21 20:25:45 wiz Exp $

Help it find libnss3.

--- firefox_decrypt.py.orig	2018-01-25 20:30:09.000000000 +0000
+++ firefox_decrypt.py
@@ -278,7 +278,7 @@ class NSSDecoder(object):
             firefox = self.find_nss(locations, nssname)
         else:
             nssname = "libnss3.so"
-            firefox = ""  # Current directory or system lib finder
+            firefox = "@PREFIX@/lib/nss"
 
         try:
             nsslib = os.path.join(firefox, nssname)
