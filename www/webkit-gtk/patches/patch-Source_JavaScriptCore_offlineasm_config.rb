$NetBSD: patch-Source_JavaScriptCore_offlineasm_config.rb,v 1.1 2024/04/14 12:44:52 tsutsui Exp $

- Apply upstream fixes for Ruby 3.2:
  https://bugs.webkit.org/show_bug.cgi?id=246743
  https://github.com/WebKit/WebKit/commit/b7ac5d0

--- Source/JavaScriptCore/offlineasm/config.rb.orig	2024-04-14 07:14:45.898589640 +0000
+++ Source/JavaScriptCore/offlineasm/config.rb
@@ -22,11 +22,11 @@
 # THE POSSIBILITY OF SUCH DAMAGE.
 
 buildProductsDirectory = ENV['BUILT_PRODUCTS_DIR'];
-if buildProductsDirectory and File.exists?(buildProductsDirectory)
+if buildProductsDirectory and File.exist?(buildProductsDirectory)
     $: << "#{buildProductsDirectory}/usr/local/include/WebKitAdditions/Scripts"
 end
 sdkRootDirectory = ENV['SDKROOT'];
-if sdkRootDirectory and File.exists?(sdkRootDirectory)
+if sdkRootDirectory and File.exist?(sdkRootDirectory)
     $: << "#{sdkRootDirectory}/usr/local/include/WebKitAdditions/Scripts"
 end
 
