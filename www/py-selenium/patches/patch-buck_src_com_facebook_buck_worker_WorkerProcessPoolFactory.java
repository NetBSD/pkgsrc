$NetBSD: patch-buck_src_com_facebook_buck_worker_WorkerProcessPoolFactory.java,v 1.1 2017/11/11 21:30:21 tnn Exp $

Fix bash location.

--- ../buck-buck-release-be2bf932342e5d67f58c9b26f5065c745d285d0d/src/com/facebook/buck/worker/WorkerProcessPoolFactory.java.orig	2017-09-21 14:10:58.000000000 +0000
+++ ../buck-buck-release-be2bf932342e5d67f58c9b26f5065c745d285d0d/src/com/facebook/buck/worker/WorkerProcessPoolFactory.java
@@ -135,7 +135,7 @@ public class WorkerProcessPoolFactory {
     ImmutableList<String> executionArgs =
         platform == Platform.WINDOWS
             ? ImmutableList.of("cmd.exe", "/c")
-            : ImmutableList.of("/bin/bash", "-e", "-c");
+            : ImmutableList.of("/usr/bin/env", "bash", "-e", "-c");
 
     return ImmutableList.<String>builder()
         .addAll(executionArgs)
