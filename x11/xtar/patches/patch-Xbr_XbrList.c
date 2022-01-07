$NetBSD: patch-Xbr_XbrList.c,v 1.1 2022/01/07 13:02:31 nia Exp $

- Fix implicit declaration warnings.
- Add missing argument to XmScrollBarSetValues.

--- Xbr/XbrList.c.orig	1995-05-09 08:06:46.000000000 +0000
+++ Xbr/XbrList.c
@@ -24,8 +24,10 @@
  *
  */
 
+#include <stdlib.h>
 #include <Xm/Xm.h>
 #include <Xm/List.h>
+#include <Xm/ScrollBar.h>
 
 #include "XbrList.h"
 
@@ -191,7 +193,7 @@ void XbrListTop(Widget w)
     XmScrollBarGetValues(scrollbar, &value_return, &slider_size_return,
       &increment_return, &page_increment_return);    
     XmScrollBarSetValues(scrollbar, minimum, slider_size_return,
-      increment_return, page_increment_return);    
+      increment_return, page_increment_return, 0);    
 }
 
 /*----------------------------------------------------------------------------
