$NetBSD: patch-xpcom_ds_nsClassHashtable.h,v 1.1 2013/03/24 16:45:55 joerg Exp $

--- xpcom/ds/nsClassHashtable.h.orig	2003-06-19 18:42:23.000000000 +0000
+++ xpcom/ds/nsClassHashtable.h
@@ -98,7 +98,7 @@ PRBool
 nsClassHashtable<KeyClass,T>::Get(KeyType aKey, T** retVal) const
 {
   typename nsBaseHashtable<KeyClass,nsAutoPtr<T>,T*>::EntryType* ent =
-    GetEntry(aKey);
+    this->GetEntry(aKey);
 
   if (ent)
   {
