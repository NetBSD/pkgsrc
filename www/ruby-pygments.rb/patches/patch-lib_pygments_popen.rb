$NetBSD: patch-lib_pygments_popen.rb,v 1.2 2017/03/20 15:54:41 taca Exp $

* Fix path
* Fix python's name under pkgsrc.

--- lib/pygments/popen.rb.orig	2017-01-04 15:51:52.000000000 +0000
+++ lib/pygments/popen.rb
@@ -24,7 +24,7 @@ module Pygments
     # Get things started by opening a pipe to mentos (the freshmaker), a
     # Python process that talks to the Pygments library. We'll talk back and
     # forth across this pipe.
-    def start(pygments_path = File.expand_path('../../../vendor/pygments-main/', __FILE__))
+    def start(pygments_path = File.expand_path('../../vendor/pygments-main/', __FILE__))
       begin
         @log = Logger.new(ENV['MENTOS_LOG'] ||= File::NULL)
         @log.level = Logger::INFO
@@ -65,7 +65,7 @@ module Pygments
       elsif windows? && which('py')
         return 'py -2'
       end
-      return which('python2') || which('python')
+      return '@PYTHON@'
     end
 
     # Cross platform which command
