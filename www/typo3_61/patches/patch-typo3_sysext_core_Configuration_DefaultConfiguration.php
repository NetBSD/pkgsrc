$NetBSD: patch-typo3_sysext_core_Configuration_DefaultConfiguration.php,v 1.1 2013/09/13 11:53:05 taca Exp $

Fix default path for pkgsrc.

--- typo3/sysext/core/Configuration/DefaultConfiguration.php.orig	2013-04-30 06:18:56.000000000 +0000
+++ typo3/sysext/core/Configuration/DefaultConfiguration.php
@@ -38,8 +38,8 @@ return array(
 		'gdlib' => TRUE,								// Boolean: Enables the use of GD.
 		'gdlib_png' => FALSE,							// Boolean: Enables the use of GD, with PNG only. This means that all items normally generated as gif-files will be png-files instead!
 		'im' => TRUE,									// Boolean: Enables the use of IM.
-		'im_path' => '/usr/bin/',						// Path to the IM tools 'convert', 'combine', 'identify'.
-		'im_path_lzw' => '/usr/bin/',					// Path to the IM tool 'convert' with LZW enabled! See 'gif_compress'. If your version 4.2.9 of ImageMagick is compiled with LZW you may leave this field blank AND disable the flag 'gif_compress'! Tip: You can call LZW 'convert' with a prefix like 'myver_convert' by setting this path with it, eg. '/usr/bin/myver_' instead of just '/usr/bin/'.
+		'im_path' => '@PREFIX@/bin/',						// Path to the IM tools 'convert', 'combine', 'identify'.
+		'im_path_lzw' => '@PREFIX@/bin/',					// Path to the IM tool 'convert' with LZW enabled! See 'gif_compress'. If your version 4.2.9 of ImageMagick is compiled with LZW you may leave this field blank AND disable the flag 'gif_compress'! Tip: You can call LZW 'convert' with a prefix like 'myver_convert' by setting this path with it, eg. '/usr/bin/myver_' instead of just '/usr/bin/'.
 		'im_version_5' => 'im6',						// String: Set this either to "im6" or "gm" (uses GraphicsMagick instead of ImageMagick). Setting this value will automatically configure some settings for use with the specified program version.
 		'im_negate_mask' => FALSE,						// Boolean: Indicates if the mask images should be inverted first. This depends of the ImageMagick version. Below ver. 5.1 this should be FALSE. Above ImageMagick version 5.2+ it should be TRUE. Just set the flag if the masks works opposite the intension!
 		'im_imvMaskState' => FALSE,						// Boolean: If set, the 'im_negate_mask' state is inverted. This is very useful with newer versions of IM5 (at least 5.4.3+) where the 'im_version_5' setting will set 'im_negate_mask' which will eventually be wrong... Halleluja for ImageMagick - have I ever regreted using that package...
