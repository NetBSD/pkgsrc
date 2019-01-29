$NetBSD: patch-src_imports_imports.pro,v 1.1.2.2 2019/01/29 14:16:59 bsiegert Exp $

Don't try to detect qml module.  Would be cyclic dependency.

--- src/imports/imports.pro.orig	2018-11-02 15:13:28.000000000 +0000
+++ src/imports/imports.pro
@@ -1,3 +1,3 @@
 TEMPLATE = subdirs
 
-qtHaveModule(qml): SUBDIRS += xmllistmodel
+#qtHaveModule(qml): SUBDIRS += xmllistmodel
