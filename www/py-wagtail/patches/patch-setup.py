$NetBSD: patch-setup.py,v 1.1 2020/08/04 01:04:34 joerg Exp $

Unrestrict dependencies

--- setup.py.orig	2020-07-22 01:21:30.195100879 +0000
+++ setup.py
@@ -26,12 +26,12 @@ install_requires = [
     "django-taggit>=1.0,<2.0",
     "django-treebeard>=4.2.0,<5.0",
     "djangorestframework>=3.7.4,<4.0",
-    "draftjs_exporter>=2.1.5,<3.0",
+    "draftjs_exporter>=2.1.5,<4.2",
     "Pillow>=4.0.0,<8.0.0",
-    "beautifulsoup4>=4.8,<4.9",
+    "beautifulsoup4>=4.8,<5.0",
     "html5lib>=0.999,<2",
     "Unidecode>=0.04.14,<2.0",
-    "Willow>=1.3,<1.4",
+    "Willow>=1.3,<1.5",
     "requests>=2.11.1,<3.0",
     "l18n>=2018.5",
     "xlsxwriter>=1.2.8,<2.0",
