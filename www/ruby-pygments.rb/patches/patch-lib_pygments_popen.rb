$NetBSD: patch-lib_pygments_popen.rb,v 1.1 2015/11/23 07:23:50 taca Exp $

* Fix path
* Fix python's name under pkgsrc.

--- lib/pygments/popen.rb.orig	2015-11-18 02:47:26.000000000 +0000
+++ lib/pygments/popen.rb
@@ -19,7 +19,7 @@ module Pygments
     # Get things started by opening a pipe to mentos (the freshmaker), a
     # Python process that talks to the Pygments library. We'll talk back and
     # forth across this pipe.
-    def start(pygments_path = File.expand_path('../../../vendor/pygments-main/', __FILE__))
+    def start(pygments_path = File.expand_path('../../vendor/pygments-main/', __FILE__))
       is_windows = RUBY_PLATFORM =~ /mswin|mingw/
       begin
         @log = Logger.new(ENV['MENTOS_LOG'] ||= is_windows ? 'NUL:' : '/dev/null')
@@ -44,10 +44,7 @@ module Pygments
 
     # Detect a suitable Python binary to use.
     def python_binary(is_windows)
-      if is_windows && which('py')
-        return 'py -2'
-      end
-      return which('python2') || 'python'
+      return '@PYTHON@'
     end
 
     # Cross platform which command
