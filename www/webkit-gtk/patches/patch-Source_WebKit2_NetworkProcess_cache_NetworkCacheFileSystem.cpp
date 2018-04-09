$NetBSD: patch-Source_WebKit2_NetworkProcess_cache_NetworkCacheFileSystem.cpp,v 1.2 2018/04/09 08:33:48 wiz Exp $

SunOS does not support dirent d_type.

--- Source/WebKit/NetworkProcess/cache/NetworkCacheFileSystem.cpp.orig	2017-02-20 16:20:17.000000000 +0000
+++ Source/WebKit/NetworkProcess/cache/NetworkCacheFileSystem.cpp
@@ -52,6 +52,12 @@ namespace NetworkCache {
 
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
@@ -65,12 +71,20 @@ static DirectoryEntryType directoryEntry
 
 void traverseDirectory(const String& path, const Function<void (const String&, DirectoryEntryType)>& function)
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
@@ -78,7 +92,11 @@ void traverseDirectory(const String& pat
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
