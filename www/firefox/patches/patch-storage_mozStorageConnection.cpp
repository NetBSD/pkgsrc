$NetBSD: patch-storage_mozStorageConnection.cpp,v 1.1 2015/09/23 06:44:42 ryoon Exp $

--- storage/mozStorageConnection.cpp.orig	2015-08-24 21:53:07.000000000 +0000
+++ storage/mozStorageConnection.cpp
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
 
