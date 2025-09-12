$NetBSD: patch-third__party_leveldatabase_env__chromium.cc,v 1.7 2025/09/12 16:02:35 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/leveldatabase/env_chromium.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ third_party/leveldatabase/env_chromium.cc
@@ -330,7 +330,8 @@ ChromiumWritableFile::ChromiumWritableFi
 
 Status ChromiumWritableFile::SyncParent() {
   TRACE_EVENT0("leveldb", "SyncParent");
-#if defined(OS_POSIX) || defined(OS_FUCHSIA)
+// pledge violation (directory passed as fd)
+#if (defined(OS_POSIX) || defined(OS_FUCHSIA)) && !defined(OS_OPENBSD)
   FilePath path = FilePath::FromUTF8Unsafe(parent_dir_);
   FileErrorOr<base::File> result = filesystem_->OpenFile(
       path, base::File::FLAG_OPEN | base::File::FLAG_READ);
