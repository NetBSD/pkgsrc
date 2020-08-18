$NetBSD: patch-setup.py,v 1.2 2020/08/18 01:16:13 joerg Exp $

Unrestrict dependencies

--- setup.py.orig	2020-08-11 09:56:22.000000000 +0000
+++ setup.py
@@ -27,9 +27,9 @@ install_requires = [
     "django-treebeard>=4.2.0,<5.0",
     "djangorestframework>=3.11.1,<4.0",
     "django-filter>=2.2,<3.0",
-    "draftjs_exporter>=2.1.5,<3.0",
+    "draftjs_exporter>=2.1.5,<4.2",
     "Pillow>=4.0.0,<8.0.0",
-    "beautifulsoup4>=4.8,<4.9",
+    "beautifulsoup4>=4.8,<5.0",
     "html5lib>=0.999,<2",
     "Unidecode>=0.04.14,<2.0",
     "Willow>=1.4,<1.5",
