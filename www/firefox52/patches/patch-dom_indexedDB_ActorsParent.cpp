$NetBSD: patch-dom_indexedDB_ActorsParent.cpp,v 1.1 2021/06/16 22:21:12 nia Exp $

Avoid macro conflict with NSS 3.66
https://bugzilla.mozilla.org/show_bug.cgi?id=1714311

--- dom/indexedDB/ActorsParent.cpp.orig	2018-06-21 18:53:54.000000000 +0000
+++ dom/indexedDB/ActorsParent.cpp
@@ -11529,7 +11529,7 @@ AutoSavepoint::~AutoSavepoint()
     MOZ_ASSERT(mDEBUGTransaction->GetMode() == IDBTransaction::READ_WRITE ||
                mDEBUGTransaction->GetMode() ==
                  IDBTransaction::READ_WRITE_FLUSH ||
-               mDEBUGTransaction->GetMode() == IDBTransaction::CLEANUP ||
+               mDEBUGTransaction->GetMode() == IDBTransaction::TRANSACTION_CLEANUP ||
                mDEBUGTransaction->GetMode() == IDBTransaction::VERSION_CHANGE);
 
     if (NS_FAILED(mConnection->RollbackSavepoint())) {
@@ -11545,7 +11545,7 @@ AutoSavepoint::Start(const TransactionBa
   MOZ_ASSERT(aTransaction);
   MOZ_ASSERT(aTransaction->GetMode() == IDBTransaction::READ_WRITE ||
              aTransaction->GetMode() == IDBTransaction::READ_WRITE_FLUSH ||
-             aTransaction->GetMode() == IDBTransaction::CLEANUP ||
+             aTransaction->GetMode() == IDBTransaction::TRANSACTION_CLEANUP ||
              aTransaction->GetMode() == IDBTransaction::VERSION_CHANGE);
 
   DatabaseConnection* connection = aTransaction->GetDatabase()->GetConnection();
@@ -14692,7 +14692,7 @@ Database::AllocPBackgroundIDBTransaction
   if (NS_WARN_IF(aMode != IDBTransaction::READ_ONLY &&
                  aMode != IDBTransaction::READ_WRITE &&
                  aMode != IDBTransaction::READ_WRITE_FLUSH &&
-                 aMode != IDBTransaction::CLEANUP)) {
+                 aMode != IDBTransaction::TRANSACTION_CLEANUP)) {
     ASSERT_UNLESS_FUZZING();
     return nullptr;
   }
@@ -14701,7 +14701,7 @@ Database::AllocPBackgroundIDBTransaction
   // has write access.
   if (NS_WARN_IF((aMode == IDBTransaction::READ_WRITE ||
                   aMode == IDBTransaction::READ_WRITE_FLUSH ||
-                  aMode == IDBTransaction::CLEANUP) &&
+                  aMode == IDBTransaction::TRANSACTION_CLEANUP) &&
                  mPrincipalInfo.type() == PrincipalInfo::TSystemPrincipalInfo &&
                  !mChromeWriteAccessAllowed)) {
     return nullptr;
@@ -14767,7 +14767,7 @@ Database::RecvPBackgroundIDBTransactionC
   MOZ_ASSERT(aMode == IDBTransaction::READ_ONLY ||
              aMode == IDBTransaction::READ_WRITE ||
              aMode == IDBTransaction::READ_WRITE_FLUSH ||
-             aMode == IDBTransaction::CLEANUP);
+             aMode == IDBTransaction::TRANSACTION_CLEANUP);
   MOZ_ASSERT(!mClosed);
 
   if (IsInvalidated()) {
@@ -14926,7 +14926,7 @@ StartTransactionOp::DoDatabaseWork(Datab
 
   Transaction()->SetActiveOnConnectionThread();
 
-  if (Transaction()->GetMode() == IDBTransaction::CLEANUP) {
+  if (Transaction()->GetMode() == IDBTransaction::TRANSACTION_CLEANUP) {
     nsresult rv = aConnection->DisableQuotaChecks();
     if (NS_WARN_IF(NS_FAILED(rv))) {
       return rv;
@@ -15245,7 +15245,7 @@ TransactionBase::VerifyRequestParams(con
     case RequestParams::TObjectStoreDeleteParams: {
       if (NS_WARN_IF(mMode != IDBTransaction::READ_WRITE &&
                      mMode != IDBTransaction::READ_WRITE_FLUSH &&
-                     mMode != IDBTransaction::CLEANUP &&
+                     mMode != IDBTransaction::TRANSACTION_CLEANUP &&
                      mMode != IDBTransaction::VERSION_CHANGE)) {
         ASSERT_UNLESS_FUZZING();
         return false;
@@ -15269,7 +15269,7 @@ TransactionBase::VerifyRequestParams(con
     case RequestParams::TObjectStoreClearParams: {
       if (NS_WARN_IF(mMode != IDBTransaction::READ_WRITE &&
                      mMode != IDBTransaction::READ_WRITE_FLUSH &&
-                     mMode != IDBTransaction::CLEANUP &&
+                     mMode != IDBTransaction::TRANSACTION_CLEANUP &&
                      mMode != IDBTransaction::VERSION_CHANGE)) {
         ASSERT_UNLESS_FUZZING();
         return false;
@@ -23959,7 +23959,7 @@ CommitOp::WriteAutoIncrementCounts()
   mTransaction->AssertIsOnConnectionThread();
   MOZ_ASSERT(mTransaction->GetMode() == IDBTransaction::READ_WRITE ||
              mTransaction->GetMode() == IDBTransaction::READ_WRITE_FLUSH ||
-             mTransaction->GetMode() == IDBTransaction::CLEANUP ||
+             mTransaction->GetMode() == IDBTransaction::TRANSACTION_CLEANUP ||
              mTransaction->GetMode() == IDBTransaction::VERSION_CHANGE);
 
   const nsTArray<RefPtr<FullObjectStoreMetadata>>& metadataArray =
@@ -24027,7 +24027,7 @@ CommitOp::CommitOrRollbackAutoIncrementC
   mTransaction->AssertIsOnConnectionThread();
   MOZ_ASSERT(mTransaction->GetMode() == IDBTransaction::READ_WRITE ||
              mTransaction->GetMode() == IDBTransaction::READ_WRITE_FLUSH ||
-             mTransaction->GetMode() == IDBTransaction::CLEANUP ||
+             mTransaction->GetMode() == IDBTransaction::TRANSACTION_CLEANUP ||
              mTransaction->GetMode() == IDBTransaction::VERSION_CHANGE);
 
   nsTArray<RefPtr<FullObjectStoreMetadata>>& metadataArray =
@@ -24161,7 +24161,7 @@ CommitOp::Run()
 
       connection->FinishWriteTransaction();
 
-      if (mTransaction->GetMode() == IDBTransaction::CLEANUP) {
+      if (mTransaction->GetMode() == IDBTransaction::TRANSACTION_CLEANUP) {
         connection->DoIdleProcessing(/* aNeedsCheckpoint */ true);
 
         connection->EnableQuotaChecks();
