$NetBSD: patch-dom_indexedDB_ProfilerHelpers.h,v 1.1 2021/06/18 13:30:32 nia Exp $

Avoid macro conflict with NSS 3.66
https://bugzilla.mozilla.org/show_bug.cgi?id=1714311

--- dom/indexedDB/ProfilerHelpers.h.orig	2020-08-17 18:26:22.000000000 +0000
+++ dom/indexedDB/ProfilerHelpers.h
@@ -119,7 +119,7 @@ class MOZ_STACK_CLASS LoggingString fina
       case IDBTransaction::READ_WRITE_FLUSH:
         AppendLiteral("\"readwriteflush\"");
         break;
-      case IDBTransaction::CLEANUP:
+      case IDBTransaction::TRANSACTION_CLEANUP:
         AppendLiteral("\"cleanup\"");
         break;
       case IDBTransaction::VERSION_CHANGE:
