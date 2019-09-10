$NetBSD: patch-Source_WTF_wtf_FileSystem.cpp,v 1.2 2019/09/10 22:10:04 leot Exp $

Support MAP_FILE if unavailable.

--- Source/WTF/wtf/FileSystem.cpp.orig	2019-08-28 11:46:29.000000000 +0000
+++ Source/WTF/wtf/FileSystem.cpp
@@ -324,6 +324,9 @@ bool MappedFileData::mapFileHandle(Platf
         return true;
     }
 
+#ifndef MAP_FILE
+#define MAP_FILE	0
+#endif
     void* data = mmap(0, size, PROT_READ, MAP_FILE | (mode == MappedFileMode::Shared ? MAP_SHARED : MAP_PRIVATE), fd, 0);
 
     if (data == MAP_FAILED) {
