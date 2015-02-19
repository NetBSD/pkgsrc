$NetBSD: patch-typo3_sysext_core_Configuration_DefaultConfiguration.php,v 1.1 2015/02/19 15:21:19 taca Exp $

Fix default path for pkgsrc.

--- typo3/sysext/core/Configuration/DefaultConfiguration.php.orig	2014-12-10 10:45:42.000000000 +0000
+++ typo3/sysext/core/Configuration/DefaultConfiguration.php
@@ -29,8 +29,8 @@ return array(
 		'gdlib' => TRUE,								// Boolean: Enables the use of GD.
 		'gdlib_png' => FALSE,							// Boolean: Enables the use of GD, with PNG only. This means that all items normally generated as gif-files will be png-files instead!
 		'im' => TRUE,									// Boolean: Enables the use of IM.
-		'im_path' => '/usr/bin/',						// Path to the IM tools 'convert', 'combine', 'identify'.
-		'im_path_lzw' => '/usr/bin/',					// Path to the IM tool 'convert' with LZW enabled! See 'gif_compress'. If your version 4.2.9 of ImageMagick is compiled with LZW you may leave this field blank AND disable the flag 'gif_compress'! Tip: You can call LZW 'convert' with a prefix like 'myver_convert' by setting this path with it, eg. '/usr/bin/myver_' instead of just '/usr/bin/'.
+		'im_path' => '@PREFIX@/bin/',						// Path to the IM tools 'convert', 'combine', 'identify'.
+		'im_path_lzw' => '@PREFIX@/bin/',					// Path to the IM tool 'convert' with LZW enabled! See 'gif_compress'. If your version 4.2.9 of ImageMagick is compiled with LZW you may leave this field blank AND disable the flag 'gif_compress'! Tip: You can call LZW 'convert' with a prefix like 'myver_convert' by setting this path with it, eg. '/usr/bin/myver_' instead of just '/usr/bin/'.
 		'im_version_5' => 'im6',						// String: Set this either to "im6" or "gm" (uses GraphicsMagick instead of ImageMagick). Setting this value will automatically configure some settings for use with the specified program version.
 		'im_v5effects' => 0,							// <p>Integer (-1, 0, 1)</p><dl><dt>0</dt><dd>disabled</dd><dt>-1</dt><dd>Do not sharpen images by default</dd><dt>1</dt><dd>All; blur and sharpening is allowed in ImageMagick.</dd></dl>
 		'im_mask_temp_ext_gif' => 1,					// Boolean: This should be set if ImageMagick is version 5+. This is used in \TYPO3\CMS\Frontend\ContentObject\ContentObjectRenderer for masking images and the extension png is normally used because it's faster than gif for temporary files. But png seems not to work with some IM 5+ versions, so...
