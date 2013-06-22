$NetBSD: patch-dolphin_src_kitemviews_kfileitemmodelrolesupdater.cpp,v 1.1 2013/06/22 20:18:26 jperkin Exp $

Avoid non-portable dirent d_type on SunOS.

--- dolphin/src/kitemviews/kfileitemmodelrolesupdater.cpp.orig	2013-05-03 04:36:32.006246684 +0000
+++ dolphin/src/kitemviews/kfileitemmodelrolesupdater.cpp
@@ -1186,10 +1186,14 @@ int KFileItemModelRolesUpdater::subItems
             // If only directories are counted, consider an unknown file type and links also
             // as directory instead of trying to do an expensive stat()
             // (see bugs 292642 and 299997).
+#ifdef __sun
+            const bool countEntry = !showFoldersOnly;
+#else
             const bool countEntry = !showFoldersOnly ||
                                     dirEntry->d_type == DT_DIR ||
                                     dirEntry->d_type == DT_LNK ||
                                     dirEntry->d_type == DT_UNKNOWN;
+#endif
             if (countEntry) {
                 ++count;
             }
