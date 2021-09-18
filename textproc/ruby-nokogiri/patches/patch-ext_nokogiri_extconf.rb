$NetBSD: patch-ext_nokogiri_extconf.rb,v 1.1 2021/09/18 08:05:09 taca Exp $

Allow depending to mini_portile2 2.6.1 and later.

--- ext/nokogiri/extconf.rb.orig	2021-09-18 07:53:47.719767565 +0000
+++ ext/nokogiri/extconf.rb
@@ -14,7 +14,7 @@ RECOMMENDED_LIBXML_VERSION = "2.9.3"
 
 # The gem version constraint in the Rakefile is not respected at install time.
 # Keep this version in sync with the one in the Rakefile !
-REQUIRED_MINI_PORTILE_VERSION = "~> 2.6.1"
+REQUIRED_MINI_PORTILE_VERSION = ">= 2.6.1"
 REQUIRED_PKG_CONFIG_VERSION = "~> 1.1"
 
 # Keep track of what versions of what libraries we build against
