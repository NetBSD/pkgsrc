$NetBSD: patch-Xbr_XbrList.h,v 1.1 2022/01/07 12:43:14 nia Exp $

- "implicit int" may have been cool in 1995, but it now produces
  compiler warnings.

--- Xbr/XbrList.h.orig	1995-05-09 08:06:46.000000000 +0000
+++ Xbr/XbrList.h
@@ -29,7 +29,7 @@ extern void XbrListClear(Widget);
 extern void XbrListAddItem(Widget, char *, int);
 extern char **XbrListGetSelection(Widget);
 extern void XbrListSelectionFree(char **);
-extern XbrListItemSelected(Widget, int *);
+extern int XbrListItemSelected(Widget, int *);
 extern void XbrListTop(Widget);
 extern int XbrListNumItems(Widget);
 
