$NetBSD: patch-quanta_treeviews_projecttreeview.h,v 1.1 2013/03/26 23:30:47 joerg Exp $

--- quanta/treeviews/projecttreeview.h.orig	2013-03-26 21:15:58.000000000 +0000
+++ quanta/treeviews/projecttreeview.h
@@ -22,7 +22,9 @@
 #include "basetreeview.h"
 //#include "projecturl.h"
 
-class KIO::Job;
+namespace KIO {
+    class Job;
+}
 class FileInfoDlg;
 class ProjectList;
 
