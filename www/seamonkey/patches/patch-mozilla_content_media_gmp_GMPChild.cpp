$NetBSD: patch-mozilla_content_media_gmp_GMPChild.cpp,v 1.2 2015/02/15 02:11:03 ryoon Exp $

--- mozilla/content/media/gmp/GMPChild.cpp.orig	2015-02-05 04:39:37.000000000 +0000
+++ mozilla/content/media/gmp/GMPChild.cpp
@@ -91,21 +91,14 @@ GetFileBase(const std::string& aPluginPa
   }
 #endif
 
-  nsCOMPtr<nsIFile> parent;
-  rv = aFileBase->GetParent(getter_AddRefs(parent));
-  if (NS_FAILED(rv)) {
-    return false;
-  }
-
-  nsAutoString parentLeafName;
-  rv = parent->GetLeafName(parentLeafName);
-  if (NS_FAILED(rv)) {
+  nsAutoString leafName;
+  if (NS_FAILED(aFileBase->GetLeafName(leafName))) {
     return false;
   }
 
-  aBaseName = Substring(parentLeafName,
+  aBaseName = Substring(leafName,
                         4,
-                        parentLeafName.Length() - 1);
+                        leafName.Length() - 1);
   return true;
 }
 
