$NetBSD: patch-src-weeport.hh,v 1.1 2011/11/22 20:03:56 joerg Exp $

--- src/weeport.hh.orig	2011-11-22 19:09:45.000000000 +0000
+++ src/weeport.hh
@@ -31,7 +31,9 @@
 #include <qfont.h>
 #include <qtextview.h>
 
-#include <vector.h>
+#include <vector>
+
+using namespace std;
 
 class QListBox;
 class QPopupMenu;
