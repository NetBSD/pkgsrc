$NetBSD: patch-src-sucker.hh,v 1.1 2011/11/22 20:03:56 joerg Exp $

--- src/sucker.hh.orig	2011-11-22 19:09:36.000000000 +0000
+++ src/sucker.hh
@@ -29,8 +29,9 @@
 #include <qstring.h>
 #include <qtable.h>
 #include <qdatetime.h>
-#include <vector.h>
+#include <vector>
 
+using namespace std;
 
 /********************************************************************
    class for handling projects
