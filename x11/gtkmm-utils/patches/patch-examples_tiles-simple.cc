$NetBSD: patch-examples_tiles-simple.cc,v 1.1 2013/04/30 22:32:43 joerg Exp $

--- examples/tiles-simple.cc.orig	2013-04-30 21:46:09.000000000 +0000
+++ examples/tiles-simple.cc
@@ -24,8 +24,6 @@
 #include <iostream>
 #include "tiles-simple.h"
 
-using std::tr1::shared_ptr;
-
 ExampleWindow::ExampleWindow()
     :
     show_navigation_("Show navigation bar"),
