$NetBSD: patch-dom_indexedDB_IDBTransaction.cpp,v 1.1 2021/06/18 13:30:32 nia Exp $

Avoid macro conflict with NSS 3.66
https://bugzilla.mozilla.org/show_bug.cgi?id=1714311

--- dom/indexedDB/IDBTransaction.cpp.orig	2020-08-17 18:26:22.000000000 +0000
+++ dom/indexedDB/IDBTransaction.cpp
@@ -177,7 +177,7 @@ already_AddRefed<IDBTransaction> IDBTran
   aDatabase->AssertIsOnOwningThread();
   MOZ_ASSERT(!aObjectStoreNames.IsEmpty());
   MOZ_ASSERT(aMode == READ_ONLY || aMode == READ_WRITE ||
-             aMode == READ_WRITE_FLUSH || aMode == CLEANUP);
+             aMode == READ_WRITE_FLUSH || aMode == TRANSACTION_CLEANUP);
 
   RefPtr<IDBTransaction> transaction =
       new IDBTransaction(aDatabase, aObjectStoreNames, aMode);
@@ -819,7 +819,7 @@ IDBTransactionMode IDBTransaction::GetMo
     case READ_WRITE_FLUSH:
       return IDBTransactionMode::Readwriteflush;
 
-    case CLEANUP:
+    case TRANSACTION_CLEANUP:
       return IDBTransactionMode::Cleanup;
 
     case VERSION_CHANGE:
