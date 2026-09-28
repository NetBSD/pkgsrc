$NetBSD: patch-media_ffmpeg_scripts_build__ffmpeg.py,v 1.27 2026/09/28 07:20:17 tnn Exp $

--- media/ffmpeg/scripts/build_ffmpeg.py.orig	2026-09-17 03:47:47.000000000 +0000
+++ media/ffmpeg/scripts/build_ffmpeg.py
@@ -33,7 +33,7 @@ sys.path.append(os.path.join(CHROMIUM_ROOT_DIR, 'build
 SUCCESS_TOKEN = 'THIS_BUILD_WORKED'
 
 sys.path.append(os.path.join(CHROMIUM_ROOT_DIR, 'build'))
-import gn_helpers
+#import gn_helpers
 
 BRANDINGS = [
     'Chrome',
@@ -43,6 +43,9 @@ ARCH_MAP = {
 ARCH_MAP = {
     'android': ['ia32', 'x64', 'arm-neon', 'arm64'],
     'linux': ['ia32', 'x64', 'noasm-x64', 'arm-neon', 'arm64', 'riscv64'],
+    'openbsd': ['x64', 'arm64', 'ia32'],
+    'freebsd': ['x64', 'arm64', 'ia32'],
+    'netbsd': ['x64', 'arm64', 'ia32'],
     'mac': ['x64', 'arm64'],
     'win': ['ia32', 'x64', 'arm64'],
 }
@@ -124,7 +127,7 @@ def GetDsoName(target_os, dso_name, dso_version):
 
 
 def GetDsoName(target_os, dso_name, dso_version):
-    if target_os in ('linux', 'linux-noasm', 'android'):
+    if target_os in ('linux', 'linux-noasm', 'android', 'openbsd', 'freebsd', 'netbsd'):
         return 'lib%s.so.%s' % (dso_name, dso_version)
     elif target_os == 'mac':
         return 'lib%s.%s.dylib' % (dso_name, dso_version)
@@ -475,7 +478,7 @@ def BuildFFmpeg(target_os, target_arch, host_os, host_
     # removing <sys/sysctl.h> soon, so this is needed to silence a deprecation
     # #warning which will be converted to an error via -Werror.
     # There is also no prctl.h
-    if target_os in ['linux', 'linux-noasm']:
+    if target_os in ['linux', 'linux-noasm', 'openbsd', 'freebsd', 'netbsd']:
         pre_make_rewrites += [
             (r'(#define HAVE_SYSCTL [01])',
              r'#define HAVE_SYSCTL 0 /* \1 -- forced to 0 for Fuchsia */'),
@@ -612,7 +615,7 @@ def main(argv):
     configure_args = args[2:]
 
     if target_os not in ('android', 'linux', 'linux-noasm', 'mac', 'win',
-                         'all'):
+                         'all', 'openbsd', 'freebsd', 'netbsd'):
         parser.print_help()
         return 1
 
@@ -686,7 +689,6 @@ def ConfigureAndBuild(target_arch, target_os, host_os,
         '--disable-faan',
         '--disable-alsa',
         '--disable-iamf',
-        '--disable-checkasm',
 
 
         # Disable automatically detected external libraries. This prevents
@@ -728,7 +730,7 @@ def ConfigureAndBuild(target_arch, target_os, host_os,
             '--optflags="-O2"',
         ])
 
-    if target_os in ('linux', 'linux-noasm', 'android'):
+    if target_os in ('linux', 'linux-noasm', 'android', 'openbsd', 'freebsd', 'netbsd'):
         if target_arch == 'x64':
             if target_os == 'android':
                 configure_flags['Common'].extend([
@@ -822,12 +824,6 @@ def ConfigureAndBuild(target_arch, target_os, host_os,
                         '--extra-ldflags=--target=aarch64-linux-gnu',
                     ])
 
-                configure_flags['Common'].extend([
-                    '--target-os=linux',
-                    '--sysroot=' +
-                    os.path.join(CHROMIUM_ROOT_DIR,
-                                 'build/linux/debian_bullseye_arm64-sysroot'),
-                ])
             configure_flags['Common'].extend([
                 '--arch=aarch64',
                 '--enable-armv8',
@@ -929,7 +925,7 @@ def ConfigureAndBuild(target_arch, target_os, host_os,
         # typically be the system one, so explicitly configure use of Clang's
         # ld.lld, to ensure that things like cross-compilation and LTO work.
         # This does not work for ia32 and is always used on mac.
-        if target_arch != 'ia32' and target_os != 'mac':
+        if target_arch != 'ia32' and target_os != 'mac' and target_os != 'netbsd':
             configure_flags['Common'].append('--extra-ldflags=-fuse-ld=lld')
 
     # Should be run on Mac, unless we're cross-compiling on Linux.
