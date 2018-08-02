$NetBSD: patch-modules_system_system.tar.inc,v 1.1 2018/08/02 16:18:47 prlw1 Exp $

Issue #2946045
Unable to update modules due to Archive_Tar incompatibility with PHP 7.2
commit 127ffe91fffb5813c32490672d68c824595d75a0

--- modules/system/system.tar.inc.orig	2018-04-25 15:32:27.000000000 +0000
+++ modules/system/system.tar.inc
@@ -41,8 +41,8 @@
 
  /**
  * Note on Drupal 8 porting.
- * This file origin is Tar.php, release 1.4.0 (stable) with some code
- * from PEAR.php, release 1.9.5 (stable) both at http://pear.php.net.
+ * This file origin is Tar.php, release 1.4.3 (stable) with some code
+ * from PEAR.php, release 1.10.5 (stable) both at http://pear.php.net.
  * To simplify future porting from pear of this file, you should not
  * do cosmetic or other non significant changes to this file.
  * The following changes have been done:
@@ -259,6 +259,19 @@ class Archive_Tar
                 return false;
             }
         }
+
+
+        if (version_compare(PHP_VERSION, "5.5.0-dev") < 0) {
+            $this->_fmt = "a100filename/a8mode/a8uid/a8gid/a12size/a12mtime/" .
+                   "a8checksum/a1typeflag/a100link/a6magic/a2version/" .
+                   "a32uname/a32gname/a8devmajor/a8devminor/a131prefix";
+        } else {
+            $this->_fmt = "Z100filename/Z8mode/Z8uid/Z8gid/Z12size/Z12mtime/" .
+                   "Z8checksum/Z1typeflag/Z100link/Z6magic/Z2version/" .
+                   "Z32uname/Z32gname/Z8devmajor/Z8devminor/Z131prefix";
+        }
+
+
     }
 
     public function __destruct()
@@ -278,7 +291,7 @@ class Archive_Tar
     * @param string $ext The extension name
     * @return bool Success or not on the dl() call
     */
-    function loadExtension($ext)
+    public static function loadExtension($ext)
     {
         if (extension_loaded($ext)) {
             return true;
@@ -287,8 +300,7 @@ class Archive_Tar
         // if either returns true dl() will produce a FATAL error, stop that
         if (
             function_exists('dl') === false ||
-            ini_get('enable_dl') != 1 ||
-            ini_get('safe_mode') == 1
+            ini_get('enable_dl') != 1
         ) {
             return false;
         }
@@ -714,7 +726,7 @@ class Archive_Tar
         }
 
         // ----- Get the arguments
-        $v_att_list = & func_get_args();
+        $v_att_list = func_get_args();
 
         // ----- Read the attributes
         $i = 0;
@@ -1720,28 +1732,13 @@ class Archive_Tar
         // ----- Calculate the checksum
         $v_checksum = 0;
         // ..... First part of the header
-        for ($i = 0; $i < 148; $i++) {
-            $v_checksum += ord(substr($v_binary_data, $i, 1));
-        }
-        // ..... Ignore the checksum value and replace it by ' ' (space)
-        for ($i = 148; $i < 156; $i++) {
-            $v_checksum += ord(' ');
-        }
-        // ..... Last part of the header
-        for ($i = 156; $i < 512; $i++) {
-            $v_checksum += ord(substr($v_binary_data, $i, 1));
-        }
+        $v_binary_split = str_split($v_binary_data);
+        $v_checksum += array_sum(array_map('ord', array_slice($v_binary_split, 0, 148)));
+        $v_checksum += array_sum(array_map('ord', array(' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',)));
+        $v_checksum += array_sum(array_map('ord', array_slice($v_binary_split, 156, 512)));
 
-        if (version_compare(PHP_VERSION, "5.5.0-dev") < 0) {
-            $fmt = "a100filename/a8mode/a8uid/a8gid/a12size/a12mtime/" .
-                "a8checksum/a1typeflag/a100link/a6magic/a2version/" .
-                "a32uname/a32gname/a8devmajor/a8devminor/a131prefix";
-        } else {
-            $fmt = "Z100filename/Z8mode/Z8uid/Z8gid/Z12size/Z12mtime/" .
-                "Z8checksum/Z1typeflag/Z100link/Z6magic/Z2version/" .
-                "Z32uname/Z32gname/Z8devmajor/Z8devminor/Z131prefix";
-        }
-        $v_data = unpack($fmt, $v_binary_data);
+
+        $v_data = unpack($this->_fmt, $v_binary_data);
 
         if (strlen($v_data["prefix"]) > 0) {
             $v_data["filename"] = "$v_data[prefix]/$v_data[filename]";
@@ -1777,7 +1774,7 @@ class Archive_Tar
         $v_header['mode'] = OctDec(trim($v_data['mode']));
         $v_header['uid'] = OctDec(trim($v_data['uid']));
         $v_header['gid'] = OctDec(trim($v_data['gid']));
-        $v_header['size'] = OctDec(trim($v_data['size']));
+        $v_header['size'] = $this->_tarRecToSize($v_data['size']);
         $v_header['mtime'] = OctDec(trim($v_data['mtime']));
         if (($v_header['typeflag'] = $v_data['typeflag']) == "5") {
             $v_header['size'] = 0;
@@ -1797,6 +1794,40 @@ class Archive_Tar
     }
 
     /**
+     * Convert Tar record size to actual size
+     *
+     * @param string $tar_size
+     * @return size of tar record in bytes
+     */
+    private function _tarRecToSize($tar_size)
+    {
+        /*
+         * First byte of size has a special meaning if bit 7 is set.
+         *
+         * Bit 7 indicates base-256 encoding if set.
+         * Bit 6 is the sign bit.
+         * Bits 5:0 are most significant value bits.
+         */
+        $ch = ord($tar_size[0]);
+        if ($ch & 0x80) {
+            // Full 12-bytes record is required.
+            $rec_str = $tar_size . "\x00";
+
+            $size = ($ch & 0x40) ? -1 : 0;
+            $size = ($size << 6) | ($ch & 0x3f);
+
+            for ($num_ch = 1; $num_ch < 12; ++$num_ch) {
+                $size = ($size * 256) + ord($rec_str[$num_ch]);
+            }
+
+            return $size;
+
+        } else {
+            return OctDec(trim($tar_size));
+        }
+    }
+
+    /**
      * Detect and report a malicious file name
      *
      * @param string $file
