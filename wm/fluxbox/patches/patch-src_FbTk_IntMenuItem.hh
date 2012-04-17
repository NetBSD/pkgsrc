$NetBSD: patch-src_FbTk_IntMenuItem.hh,v 1.1 2012/04/17 17:51:38 joerg Exp $

--- src/FbTk/IntMenuItem.hh.orig	2012-03-01 15:31:11.000000000 +0000
+++ src/FbTk/IntMenuItem.hh
@@ -26,7 +26,7 @@
 
 namespace FbTk {
 
-class Accessor<class T>;
+template<> class Accessor<class T>;
 
 /// Changes an resource integer value between min and max
 class IntMenuItem: public FbTk::MenuItem {
