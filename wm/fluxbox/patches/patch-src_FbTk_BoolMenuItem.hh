$NetBSD: patch-src_FbTk_BoolMenuItem.hh,v 1.1 2012/04/17 17:51:38 joerg Exp $

--- src/FbTk/BoolMenuItem.hh.orig	2012-03-01 15:31:36.000000000 +0000
+++ src/FbTk/BoolMenuItem.hh
@@ -26,7 +26,7 @@
 
 namespace FbTk {
 
-class Accessor<class T>;
+template<> class Accessor<class T>;
 
 /// a bool menu item
 class BoolMenuItem: public FbTk::MenuItem {
