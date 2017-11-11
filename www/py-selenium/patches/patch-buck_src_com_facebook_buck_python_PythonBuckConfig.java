$NetBSD: patch-buck_src_com_facebook_buck_python_PythonBuckConfig.java,v 1.1 2017/11/11 21:30:21 tnn Exp $

Fix python binary name.

--- ../buck-buck-release-be2bf932342e5d67f58c9b26f5065c745d285d0d/src/com/facebook/buck/python/PythonBuckConfig.java.orig	2017-09-21 14:10:58.000000000 +0000
+++ ../buck-buck-release-be2bf932342e5d67f58c9b26f5065c745d285d0d/src/com/facebook/buck/python/PythonBuckConfig.java
@@ -55,7 +55,7 @@ public class PythonBuckConfig {
 
   // Prefer "python2" where available (Linux), but fall back to "python" (Mac).
   private static final ImmutableList<String> PYTHON_INTERPRETER_NAMES =
-      ImmutableList.of("python2", "python");
+      ImmutableList.of(System.getenv("PYTHON") != null ? System.getenv("PYTHON").replaceAll("^.*/", "") : "python2", "python");
 
   private static final Path DEFAULT_PATH_TO_PEX =
       Paths.get(System.getProperty("buck.path_to_pex", "src/com/facebook/buck/python/make_pex.py"))
