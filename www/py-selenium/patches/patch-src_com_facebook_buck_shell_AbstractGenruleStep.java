$NetBSD: patch-src_com_facebook_buck_shell_AbstractGenruleStep.java,v 1.1 2017/11/11 21:30:21 tnn Exp $

Fix bash location.

--- ../buck-buck-release-be2bf932342e5d67f58c9b26f5065c745d285d0d/src/com/facebook/buck/shell/AbstractGenruleStep.java.orig	2017-09-21 14:10:58.000000000 +0000
+++ ../buck-buck-release-be2bf932342e5d67f58c9b26f5065c745d285d0d/src/com/facebook/buck/shell/AbstractGenruleStep.java
@@ -173,7 +173,7 @@ public abstract class AbstractGenruleSte
 
   private enum ShellType {
     CMD_EXE("cmd", ImmutableList.of()),
-    BASH("sh", ImmutableList.of("/bin/bash", "-e")),
+    BASH("sh", ImmutableList.of("/usr/bin/env", "bash", "-e")),
     ;
     private final String extension;
     private final ImmutableList<String> executionArgs;
