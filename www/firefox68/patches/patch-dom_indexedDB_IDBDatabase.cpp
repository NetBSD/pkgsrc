$NetBSD: patch-dom_indexedDB_IDBDatabase.cpp,v 1.1 2021/06/18 13:30:32 nia Exp $

Avoid macro conflict with NSS 3.66
https://bugzilla.mozilla.org/show_bug.cgi?id=1714311

--- dom/indexedDB/IDBDatabase.cpp.orig	2020-08-17 18:26:22.000000000 +0000
+++ dom/indexedDB/IDBDatabase.cpp
@@ -599,7 +599,7 @@ nsresult IDBDatabase::Transaction(JSCont
       break;
     case IDBTransactionMode::Readwrite:
       if (mQuotaExceeded) {
-        mode = IDBTransaction::CLEANUP;
+        mode = IDBTransaction::TRANSACTION_CLEANUP;
         mQuotaExceeded = false;
       } else {
         mode = IDBTransaction::READ_WRITE;
@@ -609,7 +609,7 @@ nsresult IDBDatabase::Transaction(JSCont
       mode = IDBTransaction::READ_WRITE_FLUSH;
       break;
     case IDBTransactionMode::Cleanup:
-      mode = IDBTransaction::CLEANUP;
+      mode = IDBTransaction::TRANSACTION_CLEANUP;
       mQuotaExceeded = false;
       break;
     case IDBTransactionMode::Versionchange:
@@ -643,7 +643,7 @@ nsresult IDBDatabase::Transaction(JSCont
 
   transaction->SetBackgroundActor(actor);
 
-  if (mode == IDBTransaction::CLEANUP) {
+  if (mode == IDBTransaction::TRANSACTION_CLEANUP) {
     ExpireFileActors(/* aExpireAll */ true);
   }
 
@@ -787,7 +787,7 @@ void IDBDatabase::AbortTransactions(bool
             // We warn for any transactions that could have written data.
             case IDBTransaction::READ_WRITE:
             case IDBTransaction::READ_WRITE_FLUSH:
-            case IDBTransaction::CLEANUP:
+            case IDBTransaction::TRANSACTION_CLEANUP:
             case IDBTransaction::VERSION_CHANGE:
               transactionsThatNeedWarning.AppendElement(transaction);
               break;
