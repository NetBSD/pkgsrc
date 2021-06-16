$NetBSD: patch-dom_indexedDB_IDBTransaction.h,v 1.1 2021/06/16 22:21:12 nia Exp $

Avoid macro conflict with NSS 3.66
https://bugzilla.mozilla.org/show_bug.cgi?id=1714311

--- dom/indexedDB/IDBTransaction.h.orig	2017-04-11 02:13:20.000000000 +0000
+++ dom/indexedDB/IDBTransaction.h
@@ -59,7 +59,7 @@ public:
     READ_ONLY = 0,
     READ_WRITE,
     READ_WRITE_FLUSH,
-    CLEANUP,
+    TRANSACTION_CLEANUP,
     VERSION_CHANGE,
 
     // Only needed for IPC serialization helper, should never be used in code.
@@ -189,7 +189,7 @@ public:
     AssertIsOnOwningThread();
     return mMode == READ_WRITE ||
            mMode == READ_WRITE_FLUSH ||
-           mMode == CLEANUP ||
+           mMode == TRANSACTION_CLEANUP ||
            mMode == VERSION_CHANGE;
   }
 
