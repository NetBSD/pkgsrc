$NetBSD: patch-xpcom_ds_nsRefPtrHashtable.h,v 1.1 2013/03/24 16:45:56 joerg Exp $

--- xpcom/ds/nsRefPtrHashtable.h.orig	2004-01-31 12:37:36.000000000 +0000
+++ xpcom/ds/nsRefPtrHashtable.h
@@ -140,7 +140,7 @@ nsRefPtrHashtable<KeyClass,RefPtr>::GetW
   (KeyType aKey, PRBool* aFound) const
 {
   typename nsBaseHashtable<KeyClass, nsRefPtr<RefPtr>, RefPtr*>::EntryType* ent =
-    GetEntry(aKey);
+    this->GetEntry(aKey);
 
   if (ent)
   {
