$NetBSD: patch-buck_src_com_facebook_buck_util_environment_Platform.java,v 1.1 2017/11/11 21:30:21 tnn Exp $

buck: NetBSD support.

--- ../buck-buck-release-be2bf932342e5d67f58c9b26f5065c745d285d0d/src/com/facebook/buck/util/environment/Platform.java.orig	2017-09-21 14:10:58.000000000 +0000
+++ ../buck-buck-release-be2bf932342e5d67f58c9b26f5065c745d285d0d/src/com/facebook/buck/util/environment/Platform.java
@@ -20,6 +20,7 @@ public enum Platform {
   MACOS("OS X", "darwin"),
   WINDOWS("Windows", "windows"),
   FREEBSD("FreeBSD", "freebsd"),
+  NETBSD("NetBSD", "netbsd"),
   UNKNOWN("Unknown", "unknown");
 
   private String autoconfName;
@@ -51,6 +52,8 @@ public enum Platform {
       return WINDOWS;
     } else if (platformName.startsWith("FreeBSD")) {
       return FREEBSD;
+    } else if (platformName.startsWith("NetBSD")) {
+      return NETBSD;
     } else {
       return UNKNOWN;
     }
