$NetBSD: patch-mozilla_content_media_gmp_GMPParent.cpp,v 1.1 2014/11/02 05:40:31 ryoon Exp $

--- mozilla/content/media/gmp/GMPParent.cpp.orig	2014-10-14 06:36:06.000000000 +0000
+++ mozilla/content/media/gmp/GMPParent.cpp
@@ -87,23 +87,16 @@ GMPParent::Init(GeckoMediaPluginService 
   mService = aService;
   mDirectory = aPluginDir;
 
-  // aPluginDir is <profile-dir>/<gmp-plugin-id>/<version>
-  // where <gmp-plugin-id> should be gmp-gmpopenh264
-  nsCOMPtr<nsIFile> parent;
-  nsresult rv = aPluginDir->GetParent(getter_AddRefs(parent));
-  if (NS_FAILED(rv)) {
-    return rv;
-  }
-  nsAutoString parentLeafName;
-  rv = parent->GetLeafName(parentLeafName);
+  nsAutoString leafname;
+  nsresult rv = aPluginDir->GetLeafName(leafname);
   if (NS_FAILED(rv)) {
     return rv;
   }
   LOGD(("%s::%s: %p for %s", __CLASS__, __FUNCTION__, this, 
-       NS_LossyConvertUTF16toASCII(parentLeafName).get()));
+       NS_LossyConvertUTF16toASCII(leafname).get()));
 
-  MOZ_ASSERT(parentLeafName.Length() > 4);
-  mName = Substring(parentLeafName, 4);
+  MOZ_ASSERT(leafname.Length() > 4);
+  mName = Substring(leafname, 4);
 
   return ReadGMPMetaData();
 }
