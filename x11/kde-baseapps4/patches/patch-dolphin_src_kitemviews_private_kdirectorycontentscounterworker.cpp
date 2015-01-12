$NetBSD: patch-dolphin_src_kitemviews_private_kdirectorycontentscounterworker.cpp,v 1.1 2015/01/12 11:25:06 jperkin Exp $

SunOS does not have dirent d_type.

--- dolphin/src/kitemviews/private/kdirectorycontentscounterworker.cpp.orig	2014-11-11 11:22:05.000000000 +0000
+++ dolphin/src/kitemviews/private/kdirectorycontentscounterworker.cpp
@@ -21,6 +21,9 @@
 #include "kdirectorycontentscounterworker.h"
 
 // Required includes for subItemsCount():
+#ifdef __sun
+#include <sys/stat.h>
+#endif
 #ifdef Q_WS_WIN
     #include <QDir>
 #else
@@ -60,6 +63,9 @@ int KDirectoryContentsCounterWorker::sub
     if (dir) {  // krazy:exclude=syscalls
         count = 0;
         struct dirent *dirEntry = 0;
+#ifdef __sun
+	struct stat s;
+#endif
         while ((dirEntry = ::readdir(dir))) {
             if (dirEntry->d_name[0] == '.') {
                 if (dirEntry->d_name[1] == '\0' || !countHiddenFiles) {
@@ -75,10 +81,15 @@ int KDirectoryContentsCounterWorker::sub
             // If only directories are counted, consider an unknown file type and links also
             // as directory instead of trying to do an expensive stat()
             // (see bugs 292642 and 299997).
+#ifdef __sun
+	    stat(dirEntry->d_name, &s);
+            const bool countEntry = !countDirectoriesOnly || S_ISDIR(s.st_mode) || S_ISLNK(s.st_mode);
+#else
             const bool countEntry = !countDirectoriesOnly ||
                                     dirEntry->d_type == DT_DIR ||
                                     dirEntry->d_type == DT_LNK ||
                                     dirEntry->d_type == DT_UNKNOWN;
+#endif
             if (countEntry) {
                 ++count;
             }
