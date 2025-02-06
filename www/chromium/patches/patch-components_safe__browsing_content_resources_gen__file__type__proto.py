$NetBSD: patch-components_safe__browsing_content_resources_gen__file__type__proto.py,v 1.1 2025/02/06 09:58:02 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/safe_browsing/content/resources/gen_file_type_proto.py.orig	2024-12-17 17:58:49.000000000 +0000
+++ components/safe_browsing/content/resources/gen_file_type_proto.py
@@ -37,6 +37,9 @@ def PlatformTypes():
         "chromeos":
         download_file_types_pb2.DownloadFileType.PLATFORM_TYPE_CHROME_OS,
         "linux": download_file_types_pb2.DownloadFileType.PLATFORM_TYPE_LINUX,
+        "openbsd": download_file_types_pb2.DownloadFileType.PLATFORM_TYPE_LINUX,
+        "freebsd": download_file_types_pb2.DownloadFileType.PLATFORM_TYPE_LINUX,
+        "netbsd": download_file_types_pb2.DownloadFileType.PLATFORM_TYPE_LINUX,
         "mac": download_file_types_pb2.DownloadFileType.PLATFORM_TYPE_MAC,
         "win": download_file_types_pb2.DownloadFileType.PLATFORM_TYPE_WINDOWS,
         # LINT.ThenChange(BUILD.gn:PlatformTypes)
@@ -179,7 +182,7 @@ class DownloadFileTypeProtoGenerator(Bin
             '-t',
             '--type',
             help='The platform type. One of android, chromeos, ' +
-            'linux, mac, win')
+            'linux, mac, win, openbsd, freebsd, netbsd')
 
     def AddExtraCommandLineArgsForVirtualEnvRun(self, opts, command):
         if opts.type is not None:
