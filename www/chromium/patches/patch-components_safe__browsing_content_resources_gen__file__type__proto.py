$NetBSD: patch-components_safe__browsing_content_resources_gen__file__type__proto.py,v 1.33 2026/11/19 19:46:00 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/safe_browsing/content/resources/gen_file_type_proto.py.orig	2026-11-11 21:01:38.000000000 +0000
+++ components/safe_browsing/content/resources/gen_file_type_proto.py
@@ -38,6 +38,9 @@ def PlatformTypes():
         "android": download_file_types_pb2.DownloadFileType.PLATFORM_TYPE_ANDROID,  # noqa: F821
         "chromeos": download_file_types_pb2.DownloadFileType.PLATFORM_TYPE_CHROME_OS,  # noqa: F821
         "linux": download_file_types_pb2.DownloadFileType.PLATFORM_TYPE_LINUX,  # noqa: F821
+        "openbsd": download_file_types_pb2.DownloadFileType.PLATFORM_TYPE_LINUX,  # noqa: F821
+        "freebsd": download_file_types_pb2.DownloadFileType.PLATFORM_TYPE_LINUX,  # noqa: F821
+        "netbsd": download_file_types_pb2.DownloadFileType.PLATFORM_TYPE_LINUX,  # noqa: F821
         "mac": download_file_types_pb2.DownloadFileType.PLATFORM_TYPE_MAC,  # noqa: F821
         "win": download_file_types_pb2.DownloadFileType.PLATFORM_TYPE_WINDOWS,  # noqa: F821
         # LINT.ThenChange(BUILD.gn:PlatformTypes)
@@ -192,7 +195,7 @@ class DownloadFileTypeProtoGenerator(Bin
             '-t',
             '--type',
             help='The platform type. One of android, chromeos, '
-            + 'linux, mac, win',
+            + 'linux, mac, win, openbsd, freebsd, netbsd',
         )
 
     def AddExtraCommandLineArgsForVirtualEnvRun(self, opts, command):
