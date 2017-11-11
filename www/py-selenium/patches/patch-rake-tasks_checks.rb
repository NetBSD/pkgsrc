$NetBSD: patch-rake-tasks_checks.rb,v 1.1 2017/11/11 21:30:21 tnn Exp $

Add BSD support.

--- rake-tasks/checks.rb.orig	2017-11-06 11:27:01.000000000 +0000
+++ rake-tasks/checks.rb
@@ -14,12 +14,16 @@ def linux?
   (/linux/ =~ RbConfig::CONFIG['host_os']) != nil
 end
 
+def bsd?
+  (/.*BSD/ =~ RbConfig::CONFIG['host_os']) != nil
+end
+
 def cygwin?
   RUBY_PLATFORM.downcase.include?("cygwin")
 end
 
 def unix?
-  linux? or mac?
+  linux? or mac? or bsd?
 end
 
 def classpath_separator?
@@ -79,7 +83,7 @@ end
 
 # Think of the confusion if we called this "g++"
 def gcc?
-  linux? && present?("g++")
+  unix? && present?("g++")
 end
 
 def python?
