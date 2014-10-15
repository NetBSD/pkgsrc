$NetBSD: patch-content_media_gmp_GMPChild.cpp,v 1.1 2014/10/15 13:43:32 ryoon Exp $

--- content/media/gmp/GMPChild.cpp.orig	2014-10-11 09:06:20.000000000 +0000
+++ content/media/gmp/GMPChild.cpp
@@ -66,19 +66,11 @@ GetPluginFile(const std::string& aPlugin
   }
 #endif
 
-  nsCOMPtr<nsIFile> parent;
-  rv = aLibFile->GetParent(getter_AddRefs(parent));
-  if (NS_FAILED(rv)) {
-    return false;
-  }
-
-  nsAutoString parentLeafName;
-  rv = parent->GetLeafName(parentLeafName);
-  if (NS_FAILED(rv)) {
+  nsAutoString leafName;
+  if (NS_FAILED(aLibFile->GetLeafName(leafName))) {
     return false;
   }
-
-  nsAutoString baseName(Substring(parentLeafName, 4, parentLeafName.Length() - 1));
+  nsAutoString baseName(Substring(leafName, 4, leafName.Length() - 1));
 
 #if defined(XP_MACOSX)
   nsAutoString binaryName = NS_LITERAL_STRING("lib") + baseName + NS_LITERAL_STRING(".dylib");
