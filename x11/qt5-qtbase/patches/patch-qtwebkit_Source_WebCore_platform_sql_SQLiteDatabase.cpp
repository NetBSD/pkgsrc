$NetBSD: patch-qtwebkit_Source_WebCore_platform_sql_SQLiteDatabase.cpp,v 1.1 2013/12/13 14:38:35 ryoon Exp $

--- qtwebkit/Source/WebCore/platform/sql/SQLiteDatabase.cpp.orig	2013-11-27 01:01:43.000000000 +0000
+++ qtwebkit/Source/WebCore/platform/sql/SQLiteDatabase.cpp
@@ -127,7 +127,7 @@ void SQLiteDatabase::interrupt()
         if (!m_db)
             return;
         sqlite3_interrupt(m_db);
-        yield();
+        WTF::yield();
     }
 
     m_lockingMutex.unlock();
