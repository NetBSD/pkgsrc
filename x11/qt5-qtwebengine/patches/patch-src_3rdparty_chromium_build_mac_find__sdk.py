$NetBSD: patch-src_3rdparty_chromium_build_mac_find__sdk.py,v 1.1 2023/04/12 19:24:06 adam Exp $

Use Xcode version provided by pkgsrc.

--- src/3rdparty/chromium/build/mac/find_sdk.py.orig	2023-04-11 08:36:42.000000000 +0000
+++ src/3rdparty/chromium/build/mac/find_sdk.py
@@ -66,24 +66,19 @@ def main():
     print(err, file=sys.stderr)
     raise Exception('Error %d running xcode-select' % job.returncode)
   dev_dir = out.decode('UTF-8').rstrip()
-  sdk_dir = os.path.join(
-      dev_dir, 'Platforms/MacOSX.platform/Developer/SDKs')
+  sdk_dir = os.environ.get('OSX_SDK_PATH')
 
   if not os.path.isdir(sdk_dir):
     raise SdkError('Install Xcode, launch it, accept the license ' +
       'agreement, and run `sudo xcode-select -s /path/to/Xcode.app` ' +
       'to continue.')
-  sdks = [re.findall('^MacOSX(\d+\.\d+)\.sdk$', s) for s in os.listdir(sdk_dir)]
-  sdks = [s[0] for s in sdks if s]  # [['10.5'], ['10.6']] => ['10.5', '10.6']
-  sdks = [s for s in sdks  # ['10.5', '10.6'] => ['10.6']
-          if parse_version(s) >= parse_version(min_sdk_version)]
+  sdks = [os.environ.get('OSX_VERSION')]
   if not sdks:
     raise Exception('No %s+ SDK found' % min_sdk_version)
   best_sdk = sorted(sdks, key=parse_version)[0]
 
   if options.print_sdk_path:
-    sdk_name = 'MacOSX' + best_sdk + '.sdk'
-    print(os.path.join(sdk_dir, sdk_name))
+    print(sdk_dir)
 
   if options.print_bin_path:
     bin_path = 'Toolchains/XcodeDefault.xctoolchain/usr/bin/'
