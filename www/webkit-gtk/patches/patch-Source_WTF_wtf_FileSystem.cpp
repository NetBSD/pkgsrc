$NetBSD: patch-Source_WTF_wtf_FileSystem.cpp,v 1.1 2019/03/13 20:49:40 leot Exp $

Support MAP_FILE if unavailable.

--- Source/WTF/wtf/FileSystem.cpp.orig	2019-02-12 11:21:17.000000000 +0000
+++ Source/WTF/wtf/FileSystem.cpp
@@ -316,6 +316,9 @@ MappedFileData::MappedFileData(const Str
         return;
     }
 
+#ifndef MAP_FILE
+#define MAP_FILE	0
+#endif
     void* data = mmap(0, size, PROT_READ, MAP_FILE | MAP_SHARED, fd, 0);
     close(fd);
 
