$NetBSD: patch-src-widgets.hh,v 1.1 2011/11/22 20:03:56 joerg Exp $

--- src/widgets.hh.orig	2011-11-22 19:09:42.000000000 +0000
+++ src/widgets.hh
@@ -31,10 +31,12 @@
 #include <qcombobox.h>
 #include <qspinbox.h>
 #include <qpopupmenu.h>
-#include <vector.h>
+#include <vector>
 #include <qcheckbox.h>
 #include <qlistbox.h>
 
+using namespace std;
+
 class QToolBar;
 class QToolButton;
 class Sucker;
