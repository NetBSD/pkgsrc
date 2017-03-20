$NetBSD: patch-test_test__pygments.rb,v 1.2 2017/03/20 15:54:41 taca Exp $

* run test without install pygments.rb.

--- test/test_pygments.rb.orig	2017-01-04 15:51:52.000000000 +0000
+++ test/test_pygments.rb
@@ -1,8 +1,10 @@
 # coding: utf-8
 # frozen_string_literal: true
 
+$:.push '../lib'
+
 require 'test/unit'
-require File.join(File.dirname(__FILE__), '..', '/lib/pygments.rb')
+require 'pygments'
 ENV['mentos-test'] = "yes"
 
 
