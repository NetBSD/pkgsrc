$NetBSD: patch-ext_extconf.rb,v 1.2 2019/12/25 00:14:15 joerg Exp $

Don't enable host-specific optimisations.
Don't enable LTO.

--- ext/extconf.rb.orig	2019-09-27 13:30:47.910318310 +0000
+++ ext/extconf.rb
@@ -19,18 +19,6 @@ if enable_config('static-stdlib', false)
   $LDFLAGS << ' -static-libgcc -static-libstdc++'
 end
 
-# Set to false when building binary gems
-if enable_config('march-tune-native', true)
-  $CFLAGS << ' -march=native -mtune=native'
-  $CXXFLAGS << ' -march=native -mtune=native'
-end
-
-if enable_config('lto', true)
-  $CFLAGS << ' -flto'
-  $CXXFLAGS << ' -flto'
-  $LDFLAGS << ' -flto'
-end
-
 # Disable noisy compilation warnings.
 $warnflags = ''
 $CFLAGS.gsub!(/[\s+](-ansi|-std=[^\s]+)/, '')
