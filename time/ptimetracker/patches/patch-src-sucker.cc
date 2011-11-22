$NetBSD: patch-src-sucker.cc,v 1.1 2011/11/22 20:03:56 joerg Exp $

--- src/sucker.cc.orig	2011-11-22 19:09:34.000000000 +0000
+++ src/sucker.cc
@@ -24,7 +24,7 @@
 #include "sucker.hh"
 
 #include <math.h>
-#include <iostream.h>
+#include <iostream>
 #include <qtable.h>
 #include <qfile.h>
 #include <qtextstream.h>
@@ -33,6 +33,8 @@
 #include <qmessagebox.h>
 #include <assert.h>
 
+using namespace std;
+
 /********************************************************************
    class for handling projects
 */
