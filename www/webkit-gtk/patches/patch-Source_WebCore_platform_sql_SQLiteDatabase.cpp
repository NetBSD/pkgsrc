$NetBSD: patch-Source_WebCore_platform_sql_SQLiteDatabase.cpp,v 1.1 2012/11/07 12:21:46 jperkin Exp $

Fix "error: 'yield' was not declared in this scope"

--- Source/WebCore/platform/sql/SQLiteDatabase.cpp.orig	Wed Nov  7 07:59:38 2012
+++ Source/WebCore/platform/sql/SQLiteDatabase.cpp	Wed Nov  7 07:59:58 2012
@@ -125,7 +125,7 @@
         if (!m_db)
             return;
         sqlite3_interrupt(m_db);
-        yield();
+        WTF::yield();
     }
 
     m_lockingMutex.unlock();
