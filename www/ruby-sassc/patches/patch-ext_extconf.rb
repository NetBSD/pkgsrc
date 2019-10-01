$NetBSD: patch-ext_extconf.rb,v 1.1 2019/10/01 15:34:50 ryoon Exp $

--- ext/extconf.rb.orig	2019-09-27 13:30:47.910318310 +0000
+++ ext/extconf.rb
@@ -19,12 +19,6 @@ if enable_config('static-stdlib', false)
   $LDFLAGS << ' -static-libgcc -static-libstdc++'
 end
 
-# Set to false when building binary gems
-if enable_config('march-tune-native', true)
-  $CFLAGS << ' -march=native -mtune=native'
-  $CXXFLAGS << ' -march=native -mtune=native'
-end
-
 if enable_config('lto', true)
   $CFLAGS << ' -flto'
   $CXXFLAGS << ' -flto'
