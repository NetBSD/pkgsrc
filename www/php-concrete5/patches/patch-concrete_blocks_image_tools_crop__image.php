$NetBSD: patch-concrete_blocks_image_tools_crop__image.php,v 1.1 2012/12/24 04:39:58 ryoon Exp $

fixing minor XSS in composer image cropper
taken from https://github.com/concrete5japan/concrete5/commit/3ede1508bc2ca0f9365f25e8bf692dc8fc30780f
Thank you, taca@.

--- concrete/blocks/image/tools/crop_image.php.orig	2012-09-21 00:15:18.000000000 +0000
+++ concrete/blocks/image/tools/crop_image.php
@@ -18,5 +18,5 @@ $save_url = $url->getBlockTypeToolsUrl($
 <object type="application/x-shockwave-flash" data="<?php  echo ASSETS_URL_FLASH?>/thumbnail_editor_3.swf" width="100%" height="500" id="ccm-image-composer-thumbnail-crop">
 <param name="wmode" value="transparent">
 <param name="quality" value="high">
-<param name="flashvars" value="tint=0&amp;backgroundColor=#FFFFFF&amp;upload=true&amp;webcam=false&amp;width=<?php echo $_GET['width']?>&amp;height=<?php echo $_GET['height']?>&amp;image=<?php echo $f->getRelativePath()?>&amp;save=<?php echo urlencode($save_url)?>">
+<param name="flashvars" value="tint=0&amp;backgroundColor=#FFFFFF&amp;upload=true&amp;webcam=false&amp;width=<?php echo htmlspecialchars($_GET['width'])?>&amp;height=<?php echo htmlspecialchars($_GET['height'])?>&amp;image=<?php echo $f->getRelativePath()?>&amp;save=<?php echo urlencode($save_url)?>">
 </object>
\ No newline at end of file
