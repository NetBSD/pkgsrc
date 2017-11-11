$NetBSD: patch-buck_src_com_facebook_buck_jvm_java_JUnitStep.java,v 1.1 2017/11/11 21:30:21 tnn Exp $

buck: NetBSD support.

--- ../buck-buck-release-be2bf932342e5d67f58c9b26f5065c745d285d0d/src/com/facebook/buck/jvm/java/JUnitStep.java.orig	2017-09-21 14:10:58.000000000 +0000
+++ ../buck-buck-release-be2bf932342e5d67f58c9b26f5065c745d285d0d/src/com/facebook/buck/jvm/java/JUnitStep.java
@@ -118,6 +118,7 @@ public class JUnitStep extends ShellStep
             switch (platform) {
               case LINUX:
               case FREEBSD:
+              case NETBSD:
               case MACOS:
                 {
                   Field field = process.getClass().getDeclaredField("pid");
