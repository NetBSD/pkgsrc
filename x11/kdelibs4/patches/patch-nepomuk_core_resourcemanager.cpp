$NetBSD: patch-nepomuk_core_resourcemanager.cpp,v 1.1 2012/06/16 04:45:40 markd Exp $

ID: 528144c444ea983470b1cff678d40b1967bce3d5
Increase the ResourceManager cache size to 10000

--- nepomuk/core/resourcemanager.cpp.orig	2012-06-06 20:49:52.000000000 +0000
+++ nepomuk/core/resourcemanager.cpp
@@ -178,7 +178,7 @@ QList<Nepomuk::ResourceData*> Nepomuk::R
 
 bool Nepomuk::ResourceManagerPrivate::dataCacheFull() const
 {
-    return dataCnt >= 1000;
+    return dataCnt >= 10000;
 }
 
 
