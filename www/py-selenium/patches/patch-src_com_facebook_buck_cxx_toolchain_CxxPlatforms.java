$NetBSD: patch-src_com_facebook_buck_cxx_toolchain_CxxPlatforms.java,v 1.1 2017/11/11 21:30:21 tnn Exp $

buck: NetBSD support.

--- ../buck-buck-release-be2bf932342e5d67f58c9b26f5065c745d285d0d/src/com/facebook/buck/cxx/toolchain/CxxPlatforms.java.orig	2017-09-21 14:10:58.000000000 +0000
+++ ../buck-buck-release-be2bf932342e5d67f58c9b26f5065c745d285d0d/src/com/facebook/buck/cxx/toolchain/CxxPlatforms.java
@@ -196,6 +196,7 @@ public class CxxPlatforms {
         .put(Platform.MACOS.getAutoconfName(), InternalFlavor.of("macosx-x86_64"))
         .put(Platform.WINDOWS.getAutoconfName(), InternalFlavor.of("windows-x86_64"))
         .put(Platform.FREEBSD.getAutoconfName(), InternalFlavor.of("freebsd-x86_64"))
+        .put(Platform.NETBSD.getAutoconfName(), InternalFlavor.of("netbsd-x86_64"))
         .build();
   }
 
