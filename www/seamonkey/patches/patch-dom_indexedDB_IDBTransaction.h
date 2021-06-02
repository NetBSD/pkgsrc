$NetBSD: patch-dom_indexedDB_IDBTransaction.h,v 1.1 2021/06/02 15:39:55 wiz Exp $

This is mostly a hack, but something else defines CLEANUP to ''
which breaks compilation.

--- dom/indexedDB/IDBTransaction.h.orig	2020-02-17 23:37:49.000000000 +0000
+++ dom/indexedDB/IDBTransaction.h
@@ -43,6 +43,8 @@ class OpenCursorParams;
 class RequestParams;
 }
 
+#define CLEANUP mozilla_dom_idbtransaction_h__CLEANUP
+
 class IDBTransaction final
   : public IDBWrapperCache
   , public nsIRunnable
