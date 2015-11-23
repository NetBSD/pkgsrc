$NetBSD: patch-test_test__pygments.rb,v 1.1 2015/11/23 07:23:50 taca Exp $

* run test without install pygments.rb.

--- test/test_pygments.rb.orig	2015-11-18 03:08:00.000000000 +0000
+++ test/test_pygments.rb
@@ -1,7 +1,9 @@
 #coding: utf-8
 
+$:.push '../lib'
+
 require 'test/unit'
-require File.join(File.dirname(__FILE__), '..', '/lib/pygments.rb')
+require 'pygments'
 ENV['mentos-test'] = "yes"
 
 P = Pygments
