$NetBSD: patch-t3lib_config__default.php,v 1.1.1.1 2012/06/02 05:54:30 taca Exp $

Don't hardcode path.

--- t3lib/config_default.php.orig	2012-04-23 20:52:26.000000000 +0000
+++ t3lib/config_default.php
@@ -35,8 +35,8 @@ $TYPO3_CONF_VARS = array(
 		'gdlib_png' => FALSE,					// Boolean: Enables the use of GD, with PNG only. This means that all items normally generated as gif-files will be png-files instead!
 
 		'im' => TRUE,							// Boolean: Enables the use of IM.
-		'im_path' => '/usr/bin/',			// Path to the IM tools 'convert', 'combine', 'identify'.
-		'im_path_lzw' => '/usr/bin/',			// Path to the IM tool 'convert' with LZW enabled! See 'gif_compress'. If your version 4.2.9 of ImageMagick is compiled with LZW you may leave this field blank AND disable the flag 'gif_compress'! Tip: You can call LZW 'convert' with a prefix like 'myver_convert' by setting this path with it, eg. '/usr/bin/myver_' instead of just '/usr/bin/'.
+		'im_path' => '@PREFIX@/bin/',			// Path to the IM tools 'convert', 'combine', 'identify'.
+		'im_path_lzw' => '/@PREFIX@/bin/',			// Path to the IM tool 'convert' with LZW enabled! See 'gif_compress'. If your version 4.2.9 of ImageMagick is compiled with LZW you may leave this field blank AND disable the flag 'gif_compress'! Tip: You can call LZW 'convert' with a prefix like 'myver_convert' by setting this path with it, eg. '/usr/bin/myver_' instead of just '/usr/bin/'.
 
 		'im_version_5' => 'im6',				// String: Set this either to "im6" or "gm" (uses GraphicsMagick instead of ImageMagick). Setting this value will automatically configure some settings for use with the specified program version.
 		'im_negate_mask' => FALSE,				// Boolean: Indicates if the mask images should be inverted first. This depends of the ImageMagick version. Below ver. 5.1 this should be FALSE. Above ImageMagick version 5.2+ it should be TRUE. Just set the flag if the masks works opposite the intension!
