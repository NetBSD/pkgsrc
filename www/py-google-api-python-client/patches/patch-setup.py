$NetBSD: patch-setup.py,v 1.4 2025/04/13 20:38:29 wiz Exp $

Relax restrictions.

--- setup.py.orig	2025-03-26 20:11:02.000000000 +0000
+++ setup.py
@@ -43,7 +43,7 @@ install_requires = [
     # Until this issue is closed
     # https://github.com/googleapis/google-cloud-python/issues/10566
     "google-api-core >= 1.31.5, <3.0.0,!=2.0.*,!=2.1.*,!=2.2.*,!=2.3.0",
-    "uritemplate>=3.0.1,<5",
+    "uritemplate>=3.0.1",
 ]
 
 package_root = os.path.abspath(os.path.dirname(__file__))
