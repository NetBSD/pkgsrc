$NetBSD: patch-flask__flatpages_____init____.py,v 1.1 2014/01/19 17:42:05 wiz Exp $

Remove undefined characters; fixes build with python-3.3.

--- flask_flatpages/__init__.py.orig	2013-04-02 09:52:15.000000000 +0000
+++ flask_flatpages/__init__.py
@@ -4,7 +4,7 @@
     ~~~~~~~~~~~~~~~
 
     Flask-FlatPages provides a collections of pages to your Flask application.
-    Pages are built from “flat” text files as opposed to a relational database.
+    Pages are built from flat text files as opposed to a relational database.
 
     :copyright: (c) 2010 by Simon Sapin.
     :license: BSD, see LICENSE for more details.
