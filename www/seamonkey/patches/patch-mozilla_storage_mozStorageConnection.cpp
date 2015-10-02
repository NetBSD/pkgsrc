$NetBSD: patch-mozilla_storage_mozStorageConnection.cpp,v 1.1 2015/10/02 22:49:36 ryoon Exp $

--- mozilla/storage/mozStorageConnection.cpp.orig	2015-09-25 07:34:55.000000000 +0000
+++ mozilla/storage/mozStorageConnection.cpp
@@ -671,6 +671,13 @@ Connection::initialize(nsIFile *aDatabas
   rv = initializeInternal();
   NS_ENSURE_SUCCESS(rv, rv);
 
+  mDatabaseFile = aDatabaseFile;
+
+  // XXX tnn: the configure script demands that sqlite3 is compiled with
+  // SECURE_DELETE on by default. sqlite3 in pkgsrc does not have that,
+  // so instead we enable secure_delete manually here.
+  (void)ExecuteSimpleSQL(NS_LITERAL_CSTRING("PRAGMA secure_delete = 1;"));
+
   return NS_OK;
 }
 
