$NetBSD: patch-buck_src_com_facebook_buck_cxx_toolchain_DefaultCxxPlatforms.java,v 1.1 2017/11/11 21:30:21 tnn Exp $

buck: NetBSD support.

--- ../buck-buck-release-be2bf932342e5d67f58c9b26f5065c745d285d0d/src/com/facebook/buck/cxx/toolchain/DefaultCxxPlatforms.java.orig	2017-09-21 14:10:58.000000000 +0000
+++ ../buck-buck-release-be2bf932342e5d67f58c9b26f5065c745d285d0d/src/com/facebook/buck/cxx/toolchain/DefaultCxxPlatforms.java
@@ -126,6 +126,7 @@ public class DefaultCxxPlatforms {
         defaultToolType = Optional.of(CxxToolProvider.Type.WINDOWS);
         ranlibCommand = DEFAULT_WINDOWS_RANLIB;
         break;
+      case NETBSD:
       case FREEBSD:
         sharedLibraryExtension = "so";
         sharedLibraryVersionedExtensionFormat = "so.%s";
