$NetBSD: patch-dom_indexedDB_ActorsParent.cpp,v 1.1 2021/06/18 13:30:32 nia Exp $

Avoid macro conflict with NSS 3.66
https://bugzilla.mozilla.org/show_bug.cgi?id=1714311

--- dom/indexedDB/ActorsParent.cpp.orig	2020-08-17 18:26:22.000000000 +0000
+++ dom/indexedDB/ActorsParent.cpp
@@ -10071,7 +10071,7 @@ DatabaseConnection::AutoSavepoint::~Auto
     MOZ_ASSERT(mDEBUGTransaction->GetMode() == IDBTransaction::READ_WRITE ||
                mDEBUGTransaction->GetMode() ==
                    IDBTransaction::READ_WRITE_FLUSH ||
-               mDEBUGTransaction->GetMode() == IDBTransaction::CLEANUP ||
+               mDEBUGTransaction->GetMode() == IDBTransaction::TRANSACTION_CLEANUP ||
                mDEBUGTransaction->GetMode() == IDBTransaction::VERSION_CHANGE);
 
     if (NS_FAILED(mConnection->RollbackSavepoint())) {
@@ -10085,7 +10085,7 @@ nsresult DatabaseConnection::AutoSavepoi
   MOZ_ASSERT(aTransaction);
   MOZ_ASSERT(aTransaction->GetMode() == IDBTransaction::READ_WRITE ||
              aTransaction->GetMode() == IDBTransaction::READ_WRITE_FLUSH ||
-             aTransaction->GetMode() == IDBTransaction::CLEANUP ||
+             aTransaction->GetMode() == IDBTransaction::TRANSACTION_CLEANUP ||
              aTransaction->GetMode() == IDBTransaction::VERSION_CHANGE);
 
   DatabaseConnection* connection = aTransaction->GetDatabase()->GetConnection();
@@ -12947,7 +12947,7 @@ PBackgroundIDBTransactionParent* Databas
   if (NS_WARN_IF(aMode != IDBTransaction::READ_ONLY &&
                  aMode != IDBTransaction::READ_WRITE &&
                  aMode != IDBTransaction::READ_WRITE_FLUSH &&
-                 aMode != IDBTransaction::CLEANUP)) {
+                 aMode != IDBTransaction::TRANSACTION_CLEANUP)) {
     ASSERT_UNLESS_FUZZING();
     return nullptr;
   }
@@ -12956,7 +12956,7 @@ PBackgroundIDBTransactionParent* Databas
   // has write access.
   if (NS_WARN_IF((aMode == IDBTransaction::READ_WRITE ||
                   aMode == IDBTransaction::READ_WRITE_FLUSH ||
-                  aMode == IDBTransaction::CLEANUP) &&
+                  aMode == IDBTransaction::TRANSACTION_CLEANUP) &&
                  mPrincipalInfo.type() == PrincipalInfo::TSystemPrincipalInfo &&
                  !mChromeWriteAccessAllowed)) {
     return nullptr;
@@ -13019,7 +13019,7 @@ mozilla::ipc::IPCResult Database::RecvPB
   MOZ_ASSERT(aMode == IDBTransaction::READ_ONLY ||
              aMode == IDBTransaction::READ_WRITE ||
              aMode == IDBTransaction::READ_WRITE_FLUSH ||
-             aMode == IDBTransaction::CLEANUP);
+             aMode == IDBTransaction::TRANSACTION_CLEANUP);
   MOZ_ASSERT(!mClosed);
 
   if (IsInvalidated()) {
@@ -13161,7 +13161,7 @@ nsresult Database::StartTransactionOp::D
 
   Transaction()->SetActiveOnConnectionThread();
 
-  if (Transaction()->GetMode() == IDBTransaction::CLEANUP) {
+  if (Transaction()->GetMode() == IDBTransaction::TRANSACTION_CLEANUP) {
     nsresult rv = aConnection->DisableQuotaChecks();
     if (NS_WARN_IF(NS_FAILED(rv))) {
       return rv;
@@ -13453,7 +13453,7 @@ bool TransactionBase::VerifyRequestParam
     case RequestParams::TObjectStoreDeleteParams: {
       if (NS_WARN_IF(mMode != IDBTransaction::READ_WRITE &&
                      mMode != IDBTransaction::READ_WRITE_FLUSH &&
-                     mMode != IDBTransaction::CLEANUP &&
+                     mMode != IDBTransaction::TRANSACTION_CLEANUP &&
                      mMode != IDBTransaction::VERSION_CHANGE)) {
         ASSERT_UNLESS_FUZZING();
         return false;
@@ -13477,7 +13477,7 @@ bool TransactionBase::VerifyRequestParam
     case RequestParams::TObjectStoreClearParams: {
       if (NS_WARN_IF(mMode != IDBTransaction::READ_WRITE &&
                      mMode != IDBTransaction::READ_WRITE_FLUSH &&
-                     mMode != IDBTransaction::CLEANUP &&
+                     mMode != IDBTransaction::TRANSACTION_CLEANUP &&
                      mMode != IDBTransaction::VERSION_CHANGE)) {
         ASSERT_UNLESS_FUZZING();
         return false;
@@ -21975,7 +21975,7 @@ nsresult TransactionBase::CommitOp::Writ
   mTransaction->AssertIsOnConnectionThread();
   MOZ_ASSERT(mTransaction->GetMode() == IDBTransaction::READ_WRITE ||
              mTransaction->GetMode() == IDBTransaction::READ_WRITE_FLUSH ||
-             mTransaction->GetMode() == IDBTransaction::CLEANUP ||
+             mTransaction->GetMode() == IDBTransaction::TRANSACTION_CLEANUP ||
              mTransaction->GetMode() == IDBTransaction::VERSION_CHANGE);
 
   const nsTArray<RefPtr<FullObjectStoreMetadata>>& metadataArray =
@@ -22039,7 +22039,7 @@ void TransactionBase::CommitOp::CommitOr
   mTransaction->AssertIsOnConnectionThread();
   MOZ_ASSERT(mTransaction->GetMode() == IDBTransaction::READ_WRITE ||
              mTransaction->GetMode() == IDBTransaction::READ_WRITE_FLUSH ||
-             mTransaction->GetMode() == IDBTransaction::CLEANUP ||
+             mTransaction->GetMode() == IDBTransaction::TRANSACTION_CLEANUP ||
              mTransaction->GetMode() == IDBTransaction::VERSION_CHANGE);
 
   nsTArray<RefPtr<FullObjectStoreMetadata>>& metadataArray =
@@ -22163,7 +22163,7 @@ TransactionBase::CommitOp::Run() {
 
       connection->FinishWriteTransaction();
 
-      if (mTransaction->GetMode() == IDBTransaction::CLEANUP) {
+      if (mTransaction->GetMode() == IDBTransaction::TRANSACTION_CLEANUP) {
         connection->DoIdleProcessing(/* aNeedsCheckpoint */ true);
 
         connection->EnableQuotaChecks();
