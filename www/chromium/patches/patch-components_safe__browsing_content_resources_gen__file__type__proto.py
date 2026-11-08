$NetBSD: patch-components_safe__browsing_content_resources_gen__file__type__proto.py,v 1.32 2026/11/08 15:39:01 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/safe_browsing/content/resources/gen_file_type_proto.py.orig	2026-11-02 23:22:33.000000000 +0000
+++ components/safe_browsing/content/resources/gen_file_type_proto.py
@@ -38,6 +38,9 @@ def PlatformTypes():
         "android": download_file_types_pb2.DownloadFileType.PLATFORM_TYPE_ANDROID,
         "chromeos": download_file_types_pb2.DownloadFileType.PLATFORM_TYPE_CHROME_OS,
         "linux": download_file_types_pb2.DownloadFileType.PLATFORM_TYPE_LINUX,
+        "openbsd": download_file_types_pb2.DownloadFileType.PLATFORM_TYPE_LINUX,
+        "freebsd": download_file_types_pb2.DownloadFileType.PLATFORM_TYPE_LINUX,
+        "netbsd": download_file_types_pb2.DownloadFileType.PLATFORM_TYPE_LINUX,
         "mac": download_file_types_pb2.DownloadFileType.PLATFORM_TYPE_MAC,
         "win": download_file_types_pb2.DownloadFileType.PLATFORM_TYPE_WINDOWS,
         # LINT.ThenChange(BUILD.gn:PlatformTypes)
@@ -192,7 +195,7 @@ class DownloadFileTypeProtoGenerator(Bin
             '-t',
             '--type',
             help='The platform type. One of android, chromeos, '
-            + 'linux, mac, win',
+            + 'linux, mac, win, openbsd, freebsd, netbsd',
         )
 
     def AddExtraCommandLineArgsForVirtualEnvRun(self, opts, command):
