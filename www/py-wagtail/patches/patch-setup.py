$NetBSD: patch-setup.py,v 1.6 2023/07/06 08:34:50 wiz Exp $

Relax requirements.

--- setup.py.orig	2023-04-03 11:40:14.000000000 +0000
+++ setup.py
@@ -27,7 +27,7 @@ install_requires = [
     "djangorestframework>=3.11.1,<4.0",
     "django-filter>=2.2,<23",
     "draftjs_exporter>=2.1.5,<3.0",
-    "Pillow>=4.0.0,<10.0.0",
+    "Pillow>=4.0.0",
     "beautifulsoup4>=4.8,<4.12",
     "html5lib>=0.999,<2",
     "Willow>=1.4,<1.5",
