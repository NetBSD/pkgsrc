$NetBSD: patch-setup.py,v 1.2 2022/08/30 11:33:50 sborrill Exp $

Relax restrictions.

--- setup.py.orig	2022-08-23 15:04:32.000000000 +0100
+++ setup.py	2022-08-25 12:31:43.711533878 +0100
@@ -43,7 +43,7 @@
     # Until this issue is closed
     # https://github.com/googleapis/google-cloud-python/issues/10566
     "google-api-core >= 1.31.5, <3.0.0dev,!=2.0.*,!=2.1.*,!=2.2.*,!=2.3.0",
-    "uritemplate>=3.0.1,<5",
+    "uritemplate>=3.0.1",
 ]
 
 package_root = os.path.abspath(os.path.dirname(__file__))
