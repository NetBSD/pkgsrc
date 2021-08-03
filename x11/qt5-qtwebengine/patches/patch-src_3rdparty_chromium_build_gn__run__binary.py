$NetBSD: patch-src_3rdparty_chromium_build_gn__run__binary.py,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/build/gn_run_binary.py.orig	2020-07-08 21:40:31.000000000 +0000
+++ src/3rdparty/chromium/build/gn_run_binary.py
@@ -24,7 +24,7 @@ if not os.path.isabs(path):
 # The rest of the arguments are passed directly to the executable.
 args = [path] + sys.argv[2:]
 
-ret = subprocess.call(args)
+ret = subprocess.call(args, env={"CHROME_EXE_PATH":"${WRKSRC}/out/Release/chrome"})
 if ret != 0:
   if ret <= -100:
     # Windows error codes such as 0xC0000005 and 0xC0000409 are much easier to
