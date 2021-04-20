$NetBSD: patch-setup.py,v 1.4 2021/04/20 14:44:04 joerg Exp $

Unrestrict dependencies

--- setup.py.orig	2021-04-19 09:28:55.000000000 +0000
+++ setup.py
@@ -26,9 +26,9 @@ install_requires = [
     "django-treebeard>=4.2.0,<5.0,!=4.5",
     "djangorestframework>=3.11.1,<4.0",
     "django-filter>=2.2,<3.0",
-    "draftjs_exporter>=2.1.5,<3.0",
+    "draftjs_exporter>=2.1.5,<4.2",
     "Pillow>=4.0.0,<9.0.0",
-    "beautifulsoup4>=4.8,<4.9",
+    "beautifulsoup4>=4.8,<5.0",
     "html5lib>=0.999,<2",
     "Willow>=1.4,<1.5",
     "requests>=2.11.1,<3.0",
