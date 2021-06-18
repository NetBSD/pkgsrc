$NetBSD: patch-dom_indexedDB_IDBObjectStore.cpp,v 1.1 2021/06/18 13:30:32 nia Exp $

Avoid macro conflict with NSS 3.66
https://bugzilla.mozilla.org/show_bug.cgi?id=1714311

--- dom/indexedDB/IDBObjectStore.cpp.orig	2020-08-17 18:26:22.000000000 +0000
+++ dom/indexedDB/IDBObjectStore.cpp
@@ -1526,7 +1526,7 @@ already_AddRefed<IDBRequest> IDBObjectSt
   MOZ_ASSERT(aCx);
   MOZ_ASSERT_IF(aFromCursor, aOverwrite);
 
-  if (mTransaction->GetMode() == IDBTransaction::CLEANUP || mDeletedSpec) {
+  if (mTransaction->GetMode() == IDBTransaction::TRANSACTION_CLEANUP || mDeletedSpec) {
     aRv.Throw(NS_ERROR_DOM_INDEXEDDB_NOT_ALLOWED_ERR);
     return nullptr;
   }
