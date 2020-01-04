$NetBSD: patch-src_fs_ufs_RebuildState.h,v 1.1 2020/01/04 10:57:18 taca Exp $

Quick fix for 32bit system.

--- src/fs/ufs/RebuildState.h.orig	2019-07-09 19:05:20.000000000 +0000
+++ src/fs/ufs/RebuildState.h
@@ -54,7 +54,7 @@ public:
     dirent_t *entry;
     DIR *td;
     char fullpath[MAXPATHLEN];
-    char fullfilename[MAXPATHLEN*2];
+    char fullfilename[MAXPATHLEN*3];
 
     StoreRebuildData counts;
 
