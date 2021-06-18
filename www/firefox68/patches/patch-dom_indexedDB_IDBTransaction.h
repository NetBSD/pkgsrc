$NetBSD: patch-dom_indexedDB_IDBTransaction.h,v 1.1 2021/06/18 13:30:32 nia Exp $

Avoid macro conflict with NSS 3.66
https://bugzilla.mozilla.org/show_bug.cgi?id=1714311

--- dom/indexedDB/IDBTransaction.h.orig	2020-08-17 18:26:23.000000000 +0000
+++ dom/indexedDB/IDBTransaction.h
@@ -54,7 +54,7 @@ class IDBTransaction final : public DOME
     READ_ONLY = 0,
     READ_WRITE,
     READ_WRITE_FLUSH,
-    CLEANUP,
+    TRANSACTION_CLEANUP,
     VERSION_CHANGE,
 
     // Only needed for IPC serialization helper, should never be used in code.
@@ -169,7 +169,7 @@ class IDBTransaction final : public DOME
   bool IsWriteAllowed() const {
     AssertIsOnOwningThread();
     return mMode == READ_WRITE || mMode == READ_WRITE_FLUSH ||
-           mMode == CLEANUP || mMode == VERSION_CHANGE;
+           mMode == TRANSACTION_CLEANUP || mMode == VERSION_CHANGE;
   }
 
   bool IsAborted() const {
