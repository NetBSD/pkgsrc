$NetBSD: patch-mozilla_build_pgo_profileserver.py,v 1.5 2017/08/18 23:55:07 ryoon Exp $

--- mozilla/build/pgo/profileserver.py.orig	2017-07-07 05:26:08.000000000 +0000
+++ mozilla/build/pgo/profileserver.py
@@ -80,7 +80,7 @@ if __name__ == '__main__':
       env["MOZ_JAR_LOG_FILE"] = os.path.abspath(jarlog)
       print "jarlog: %s" % env["MOZ_JAR_LOG_FILE"]
 
-    cmdargs = ["http://localhost:%d/index.html" % PORT]
+    cmdargs = ["http://127.0.0.1:%d/index.html" % PORT]
     runner = FirefoxRunner(profile=profile,
                            binary=build.get_binary_path(where="staged-package"),
                            cmdargs=cmdargs,
