$NetBSD: patch-build_pgo_profileserver.py,v 1.1 2017/04/27 01:55:57 ryoon Exp $

--- build/pgo/profileserver.py.orig	2017-01-16 16:16:51.000000000 +0000
+++ build/pgo/profileserver.py
@@ -80,7 +80,7 @@ if __name__ == '__main__':
       env["MOZ_JAR_LOG_FILE"] = os.path.abspath(jarlog)
       print "jarlog: %s" % env["MOZ_JAR_LOG_FILE"]
 
-    cmdargs = ["http://localhost:%d/index.html" % PORT]
+    cmdargs = ["http://127.0.0.1:%d/index.html" % PORT]
     runner = FirefoxRunner(profile=profile,
                            binary=build.get_binary_path(where="staged-package"),
                            cmdargs=cmdargs,
