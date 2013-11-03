$NetBSD: patch-build_pgo_profileserver.py,v 1.1 2013/11/03 04:51:59 ryoon Exp $

--- build/pgo/profileserver.py.orig	2013-09-10 03:43:22.000000000 +0000
+++ build/pgo/profileserver.py
@@ -59,7 +59,7 @@ if __name__ == '__main__':
       env["MOZ_JAR_LOG_FILE"] = os.path.abspath(jarlog)
       print "jarlog: %s" % env["MOZ_JAR_LOG_FILE"]
 
-    cmdargs = ["http://localhost:%d/index.html" % PORT]
+    cmdargs = ["http://127.0.0.1:%d/index.html" % PORT]
     runner = FirefoxRunner(profile=profile,
                            binary=build.get_binary_path(where="staged-package"),
                            cmdargs=cmdargs,
