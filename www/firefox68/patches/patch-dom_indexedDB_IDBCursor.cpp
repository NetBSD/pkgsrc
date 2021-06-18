$NetBSD: patch-dom_indexedDB_IDBCursor.cpp,v 1.1 2021/06/18 13:30:32 nia Exp $

Avoid macro conflict with NSS 3.66
https://bugzilla.mozilla.org/show_bug.cgi?id=1714311

--- dom/indexedDB/IDBCursor.cpp.orig	2020-08-17 18:26:22.000000000 +0000
+++ dom/indexedDB/IDBCursor.cpp
@@ -630,7 +630,7 @@ already_AddRefed<IDBRequest> IDBCursor::
     return nullptr;
   }
 
-  if (mTransaction->GetMode() == IDBTransaction::CLEANUP || IsSourceDeleted() ||
+  if (mTransaction->GetMode() == IDBTransaction::TRANSACTION_CLEANUP || IsSourceDeleted() ||
       !mHaveValue || mType == Type_ObjectStoreKey || mType == Type_IndexKey ||
       mContinueCalled) {
     aRv.Throw(NS_ERROR_DOM_INDEXEDDB_NOT_ALLOWED_ERR);
