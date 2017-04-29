$NetBSD: patch-Source_WebKit2_NetworkProcess_cache_NetworkCacheFileSystem.cpp,v 1.1.2.2 2017/04/29 10:58:21 bsiegert Exp $

SunOS does not support dirent d_type.

--- Source/WebKit2/NetworkProcess/cache/NetworkCacheFileSystem.cpp.orig	2016-07-20 12:15:24.000000000 +0000
+++ Source/WebKit2/NetworkProcess/cache/NetworkCacheFileSystem.cpp
@@ -44,6 +44,12 @@ namespace NetworkCache {
 
 static DirectoryEntryType directoryEntryType(uint8_t dtype)
 {
+#ifndef DT_DIR
+#define DT_DIR	S_IFDIR
+#endif
+#ifndef DT_REG
+#define DT_REG	S_IFREG
+#endif
     switch (dtype) {
     case DT_DIR:
         return DirectoryEntryType::Directory;
@@ -57,12 +63,20 @@ static DirectoryEntryType directoryEntry
 
 void traverseDirectory(const String& path, const std::function<void (const String&, DirectoryEntryType)>& function)
 {
+#ifdef __sun
+    struct stat s;
+#endif
     DIR* dir = opendir(WebCore::fileSystemRepresentation(path).data());
     if (!dir)
         return;
     dirent* dp;
     while ((dp = readdir(dir))) {
+#ifdef __sun
+        stat(dp->d_name, &s);
+        if (s.st_mode != S_IFDIR && s.st_mode != S_IFREG)
+#else
         if (dp->d_type != DT_DIR && dp->d_type != DT_REG)
+#endif
             continue;
         const char* name = dp->d_name;
         if (!strcmp(name, ".") || !strcmp(name, ".."))
@@ -70,7 +84,11 @@ void traverseDirectory(const String& pat
         auto nameString = String::fromUTF8(name);
         if (nameString.isNull())
             continue;
+#ifdef __sun
+        function(nameString, directoryEntryType(s.st_mode));
+#else
         function(nameString, directoryEntryType(dp->d_type));
+#endif
     }
     closedir(dir);
 }
