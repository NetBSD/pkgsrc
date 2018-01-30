$NetBSD: patch-src_ruby__supportlib_phusion__passenger_platform__info_cxx__portability.rb,v 1.1 2018/01/30 12:06:48 fhajny Exp $

Default paths.

--- src/ruby_supportlib/phusion_passenger/platform_info/cxx_portability.rb.orig	2013-10-27 00:00:00.000000000 +0000
+++ src/ruby_supportlib/phusion_passenger/platform_info/cxx_portability.rb
@@ -115,7 +115,7 @@ module PhusionPassenger
     private_class_method :check_hash_map
 
     def self.default_extra_c_or_cxxflags(cc_or_cxx)
-      flags = ["-D_REENTRANT", "-I/usr/local/include"]
+      flags = ["-D_REENTRANT", "-I@PREFIX@/include"]
 
       if !send("#{cc_or_cxx}_is_sun_studio?")
         flags << "-Wall -Wextra -Wno-unused-parameter -Wno-parentheses -Wpointer-arith -Wwrite-strings -Wno-long-long"
