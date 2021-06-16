$NetBSD: patch-dom_indexedDB_IDBTransaction.cpp,v 1.1 2021/06/16 22:21:12 nia Exp $

Avoid macro conflict with NSS 3.66
https://bugzilla.mozilla.org/show_bug.cgi?id=1714311

--- dom/indexedDB/IDBTransaction.cpp.orig	2017-04-11 02:13:20.000000000 +0000
+++ dom/indexedDB/IDBTransaction.cpp
@@ -216,7 +216,7 @@ IDBTransaction::Create(JSContext* aCx, I
   MOZ_ASSERT(aMode == READ_ONLY ||
              aMode == READ_WRITE ||
              aMode == READ_WRITE_FLUSH ||
-             aMode == CLEANUP);
+             aMode == TRANSACTION_CLEANUP);
 
   RefPtr<IDBTransaction> transaction =
     new IDBTransaction(aDatabase, aObjectStoreNames, aMode);
@@ -871,7 +871,7 @@ IDBTransaction::GetMode(ErrorResult& aRv
     case READ_WRITE_FLUSH:
       return IDBTransactionMode::Readwriteflush;
 
-    case CLEANUP:
+    case TRANSACTION_CLEANUP:
       return IDBTransactionMode::Cleanup;
 
     case VERSION_CHANGE:
