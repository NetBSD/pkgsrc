$NetBSD: patch-xpcom_ds_nsBaseHashtable.h,v 1.1 2013/03/24 16:45:55 joerg Exp $

--- xpcom/ds/nsBaseHashtable.h.orig	2003-08-09 19:24:24.000000000 +0000
+++ xpcom/ds/nsBaseHashtable.h
@@ -124,7 +124,7 @@ public:
    */
   PRBool Get(KeyType aKey, UserDataType* pData) const
   {
-    EntryType* ent = GetEntry(aKey);
+    EntryType* ent = this->GetEntry(aKey);
 
     if (!ent)
       return PR_FALSE;
@@ -143,7 +143,7 @@ public:
    */
   PRBool Put(KeyType aKey, UserDataType aData)
   {
-    EntryType* ent = PutEntry(aKey);
+    EntryType* ent = this->PutEntry(aKey);
 
     if (!ent)
       return PR_FALSE;
@@ -157,7 +157,7 @@ public:
    * remove the data for the associated key
    * @param aKey the key to remove from the hashtable
    */
-  void Remove(KeyType aKey) { RemoveEntry(aKey); }
+  void Remove(KeyType aKey) { this->RemoveEntry(aKey); }
 
   /**
    * function type provided by the application for enumeration.
