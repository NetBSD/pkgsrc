$NetBSD: patch-src_ruby__supportlib_phusion__passenger_platform__info_operating__system.rb,v 1.1 2023/01/19 15:46:29 taca Exp $

Ruby 3.2 compatibility.

--- src/ruby_supportlib/phusion_passenger/platform_info/operating_system.rb.orig	2013-10-27 00:00:00.000000000 +0000
+++ src/ruby_supportlib/phusion_passenger/platform_info/operating_system.rb
@@ -236,7 +236,7 @@ module PhusionPassenger
     memoize :supports_lfence_instruction?, true
 
     def self.requires_no_tls_direct_seg_refs?
-      return File.exists?("/proc/xen/capabilities") && cpu_architectures[0] == "x86"
+      return File.exist?("/proc/xen/capabilities") && cpu_architectures[0] == "x86"
     end
     memoize :requires_no_tls_direct_seg_refs?, true
   end
