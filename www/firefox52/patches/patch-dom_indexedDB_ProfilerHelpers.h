$NetBSD: patch-dom_indexedDB_ProfilerHelpers.h,v 1.1 2021/06/16 22:21:12 nia Exp $

Avoid macro conflict with NSS 3.66
https://bugzilla.mozilla.org/show_bug.cgi?id=1714311

--- dom/indexedDB/ProfilerHelpers.h.orig	2017-04-11 02:13:20.000000000 +0000
+++ dom/indexedDB/ProfilerHelpers.h
@@ -129,7 +129,7 @@ public:
       case IDBTransaction::READ_WRITE_FLUSH:
         AppendLiteral("\"readwriteflush\"");
         break;
-      case IDBTransaction::CLEANUP:
+      case IDBTransaction::TRANSACTION_CLEANUP:
         AppendLiteral("\"cleanup\"");
         break;
       case IDBTransaction::VERSION_CHANGE:
