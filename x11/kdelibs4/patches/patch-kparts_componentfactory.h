$NetBSD: patch-kparts_componentfactory.h,v 1.1 2012/11/11 22:24:01 joerg Exp $

--- kparts/componentfactory.h.orig	2012-06-06 20:49:52.000000000 +0000
+++ kparts/componentfactory.h
@@ -81,7 +81,7 @@ namespace KParts
                                           const QStringList &args = QStringList(),
                                           int *error = 0 )
         {
-            KLibrary *library = KLibLoader::self()->library( QString( libraryName ) ); // compatibility hack
+            KLibrary *library = KLibLoader::self()->library( QString::fromAscii( libraryName ) ); // compatibility hack
             if ( !library )
             {
                 if ( error )
