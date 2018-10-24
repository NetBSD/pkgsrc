$NetBSD: patch-Source_WebKit_NetworkProcess_cache_NetworkCacheFileSystem.cpp,v 1.2 2018/10/24 18:31:07 leot Exp $

SunOS does not support DT_{DIR,REG}

--- Source/WebKit/NetworkProcess/cache/NetworkCacheFileSystem.cpp.orig	2018-07-25 11:56:32.000000000 +0000
+++ Source/WebKit/NetworkProcess/cache/NetworkCacheFileSystem.cpp
@@ -54,6 +54,12 @@ namespace NetworkCache {
 static DirectoryEntryType directoryEntryType(uint8_t dtype)
 {
 #if !OS(WINDOWS)
+#ifndef DT_DIR
+#define DT_DIR	S_IFDIR
+#endif
+#ifndef DT_REG
+#define DT_REG	S_IFREG
+#endif
     switch (dtype) {
     case DT_DIR:
         return DirectoryEntryType::Directory;
@@ -71,12 +77,20 @@ static DirectoryEntryType directoryEntry
 void traverseDirectory(const String& path, const Function<void (const String&, DirectoryEntryType)>& function)
 {
 #if !OS(WINDOWS)
+#if OS(SOLARIS)
+    struct stat s;
+#endif
     DIR* dir = opendir(WebCore::FileSystem::fileSystemRepresentation(path).data());
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
@@ -84,7 +98,11 @@ void traverseDirectory(const String& pat
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
