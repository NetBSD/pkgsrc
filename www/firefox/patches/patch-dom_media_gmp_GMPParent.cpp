$NetBSD: patch-dom_media_gmp_GMPParent.cpp,v 1.2 2015/07/03 10:25:40 ryoon Exp $

--- dom/media/gmp/GMPParent.cpp.orig	2015-06-18 20:55:35.000000000 +0000
+++ dom/media/gmp/GMPParent.cpp
@@ -101,22 +101,15 @@ GMPParent::Init(GeckoMediaPluginService 
   mService = aService;
   mDirectory = aPluginDir;
 
-  // aPluginDir is <profile-dir>/<gmp-plugin-id>/<version>
-  // where <gmp-plugin-id> should be gmp-gmpopenh264
-  nsCOMPtr<nsIFile> parent;
-  nsresult rv = aPluginDir->GetParent(getter_AddRefs(parent));
+  nsAutoString leafname;
+  nsresult rv = aPluginDir->GetLeafName(leafname);
   if (NS_FAILED(rv)) {
     return rv;
   }
-  nsAutoString parentLeafName;
-  rv = parent->GetLeafName(parentLeafName);
-  if (NS_FAILED(rv)) {
-    return rv;
-  }
-  LOGD("%s: for %s", __FUNCTION__, NS_LossyConvertUTF16toASCII(parentLeafName).get());
+  LOGD("%s: for %s", __FUNCTION__, NS_LossyConvertUTF16toASCII(leafname).get());
 
-  MOZ_ASSERT(parentLeafName.Length() > 4);
-  mName = Substring(parentLeafName, 4);
+  MOZ_ASSERT(leafname.Length() > 4);
+  mName = Substring(leafname, 4);
 
   return ReadGMPMetaData();
 }
