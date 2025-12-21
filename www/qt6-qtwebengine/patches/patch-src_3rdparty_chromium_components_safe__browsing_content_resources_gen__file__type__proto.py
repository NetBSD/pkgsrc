$NetBSD: patch-src_3rdparty_chromium_components_safe__browsing_content_resources_gen__file__type__proto.py,v 1.1 2025/12/21 09:38:24 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/safe_browsing/content/resources/gen_file_type_proto.py.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/components/safe_browsing/content/resources/gen_file_type_proto.py
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
