$NetBSD: patch-src_imports_imports.pro,v 1.1 2019/01/06 10:21:12 markd Exp $

Don't try to detect qml module.  Would be cyclic dependency.

--- src/imports/imports.pro.orig	2018-11-02 15:13:28.000000000 +0000
+++ src/imports/imports.pro
@@ -1,3 +1,3 @@
 TEMPLATE = subdirs
 
-qtHaveModule(qml): SUBDIRS += xmllistmodel
+#qtHaveModule(qml): SUBDIRS += xmllistmodel
