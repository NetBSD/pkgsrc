$NetBSD: patch-system_modules_news_dca_tl__news.php,v 1.1.2.2 2020/10/21 21:51:28 spz Exp $

Fix time range problem on positive timezone.

--- system/modules/news/dca/tl_news.php.orig	2019-04-11 11:11:34.000000000 +0000
+++ system/modules/news/dca/tl_news.php
@@ -228,7 +228,7 @@ $GLOBALS['TL_DCA']['tl_news'] = array
 			'exclude'                 => true,
 			'inputType'               => 'text',
 			'eval'                    => array('rgxp'=>'time', 'doNotCopy'=>true, 'tl_class'=>'w50'),
-			'sql'                     => "int(10) unsigned NOT NULL default '0'"
+			'sql'                     => "int(10) NOT NULL default '0'"
 		),
 		'subheadline' => array
 		(
