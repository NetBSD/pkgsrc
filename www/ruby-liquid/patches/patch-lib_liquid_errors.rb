$NetBSD: patch-lib_liquid_errors.rb,v 1.1 2024/01/21 09:07:55 taca Exp $

Remove support for taint checking.

--- lib/liquid/errors.rb.orig	2024-01-15 06:05:42.694834905 +0000
+++ lib/liquid/errors.rb
@@ -44,7 +44,6 @@ module Liquid
   StandardError = Class.new(Error)
   SyntaxError = Class.new(Error)
   StackLevelError = Class.new(Error)
-  TaintedError = Class.new(Error)
   MemoryError = Class.new(Error)
   ZeroDivisionError = Class.new(Error)
   FloatDomainError = Class.new(Error)
