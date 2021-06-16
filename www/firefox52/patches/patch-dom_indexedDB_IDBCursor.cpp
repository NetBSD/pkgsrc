$NetBSD: patch-dom_indexedDB_IDBCursor.cpp,v 1.1 2021/06/16 22:21:12 nia Exp $

Avoid macro conflict with NSS 3.66
https://bugzilla.mozilla.org/show_bug.cgi?id=1714311

--- dom/indexedDB/IDBCursor.cpp.orig	2017-04-11 02:13:20.000000000 +0000
+++ dom/indexedDB/IDBCursor.cpp
@@ -696,7 +696,7 @@ IDBCursor::Update(JSContext* aCx, JS::Ha
     return nullptr;
   }
 
-  if (mTransaction->GetMode() == IDBTransaction::CLEANUP ||
+  if (mTransaction->GetMode() == IDBTransaction::TRANSACTION_CLEANUP ||
       IsSourceDeleted() ||
       !mHaveValue ||
       mType == Type_ObjectStoreKey ||
