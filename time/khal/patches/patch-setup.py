$NetBSD: patch-setup.py,v 1.1 2024/10/31 13:35:05 leot Exp $

Make it compatible with icalendar>=6.0.0.

Shared upstream via:

 <https://github.com/pimutils/khal/pull/1364>

--- setup.py.orig	2024-10-31 13:29:01.578288212 +0000
+++ setup.py
@@ -13,7 +13,7 @@ if sys.version_info < (3, 8):
 requirements = [
     'click>=3.2',
     'click_log>=0.2.0',
-    'icalendar>=4.0.3',
+    'icalendar>=6.0.0',
     'urwid>=1.3.0',
     'pyxdg',
     'pytz',
