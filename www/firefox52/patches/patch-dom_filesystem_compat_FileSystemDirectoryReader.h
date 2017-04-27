$NetBSD: patch-dom_filesystem_compat_FileSystemDirectoryReader.h,v 1.1 2017/04/27 01:55:57 ryoon Exp $

--- dom/filesystem/compat/FileSystemDirectoryReader.h.orig	2017-04-11 02:13:18.000000000 +0000
+++ dom/filesystem/compat/FileSystemDirectoryReader.h
@@ -11,6 +11,7 @@
 #include "mozilla/ErrorResult.h"
 #include "mozilla/dom/BindingDeclarations.h"
 #include "nsCycleCollectionParticipant.h"
+#include "mozilla/dom/FileSystemDirectoryEntry.h"
 #include "nsWrapperCache.h"
 
 namespace mozilla {
