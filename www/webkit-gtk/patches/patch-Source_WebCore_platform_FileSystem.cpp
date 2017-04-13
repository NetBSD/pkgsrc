$NetBSD: patch-Source_WebCore_platform_FileSystem.cpp,v 1.1 2017/04/13 16:58:14 jperkin Exp $

Support MAP_FILE if unavailable.

--- Source/WebCore/platform/FileSystem.cpp.orig	2016-08-22 12:21:08.000000000 +0000
+++ Source/WebCore/platform/FileSystem.cpp
@@ -189,6 +189,9 @@ MappedFileData::MappedFileData(const Str
         return;
     }
 
+#ifndef MAP_FILE
+#define MAP_FILE	0
+#endif
     void* data = mmap(0, size, PROT_READ, MAP_FILE | MAP_SHARED, fd, 0);
     close(fd);
 
