$NetBSD: patch-libs_oxygen_oxygenhelper.cpp,v 1.1 2018/01/17 19:10:23 markd Exp $

gcc-7 fix

--- libs/oxygen/oxygenhelper.cpp.orig	2015-08-12 07:03:15.000000000 +0000
+++ libs/oxygen/oxygenhelper.cpp
@@ -1089,7 +1089,7 @@ namespace Oxygen
             &data);
 
         // finish if no data is found
-        if( data == None || n != 1 ) return false;
+        if( data == NULL || n != 1 ) return false;
         else return *data;
 
     }
