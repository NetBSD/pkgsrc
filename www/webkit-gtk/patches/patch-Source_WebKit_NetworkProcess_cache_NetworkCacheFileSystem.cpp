$NetBSD: patch-Source_WebKit_NetworkProcess_cache_NetworkCacheFileSystem.cpp,v 1.3 2019/03/13 20:49:41 leot Exp $

SunOS does not support DT_{DIR,REG}

--- Source/WebKit/NetworkProcess/cache/NetworkCacheFileSystem.cpp.orig	2019-02-12 11:21:18.000000000 +0000
+++ Source/WebKit/NetworkProcess/cache/NetworkCacheFileSystem.cpp
@@ -52,6 +52,12 @@ namespace WebKit {
 namespace NetworkCache {
 
 #if !OS(WINDOWS)
+#ifndef DT_DIR
+#define DT_DIR	S_IFDIR
+#endif
+#ifndef DT_REG
+#define DT_REG	S_IFREG
+#endif
 static DirectoryEntryType directoryEntryType(uint8_t dtype)
 {
     switch (dtype) {
@@ -69,13 +75,21 @@ static DirectoryEntryType directoryEntry
 
 void traverseDirectory(const String& path, const Function<void (const String&, DirectoryEntryType)>& function)
 {
+#if OS(SOLARIS)
+    struct stat s;
+#endif
 #if !OS(WINDOWS)
     DIR* dir = opendir(FileSystem::fileSystemRepresentation(path).data());
     if (!dir)
         return;
     dirent* dp;
     while ((dp = readdir(dir))) {
+#if OS(SOLARIS)
+        stat(dp->d_name, &s);
+        if (s.st_mode != S_IFDIR && s.st_mode != S_IFREG)
+#else
         if (dp->d_type != DT_DIR && dp->d_type != DT_REG)
+#endif
             continue;
         const char* name = dp->d_name;
         if (!strcmp(name, ".") || !strcmp(name, ".."))
@@ -83,7 +97,11 @@ void traverseDirectory(const String& pat
         auto nameString = String::fromUTF8(name);
         if (nameString.isNull())
             continue;
+#if OS(SOLARIS)
+        function(nameString, directoryEntryType(s.st_mode));
+#else
         function(nameString, directoryEntryType(dp->d_type));
+#endif
     }
     closedir(dir);
 #else
