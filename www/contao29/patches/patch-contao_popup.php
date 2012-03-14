$NetBSD: patch-contao_popup.php,v 1.1 2012/03/14 16:42:02 taca Exp $

* Fix vulnerability as Contao 2.11.2.

--- contao/popup.php.orig	2011-03-02 12:54:54.000000000 +0000
+++ contao/popup.php
@@ -98,6 +98,12 @@ class Popup extends Backend
 			die('File not found');
 		}
 
+		// Check whether the file is mounted (thanks to Marko Cupic)
+		if (!$this->User->hasAccess($this->strFile, 'filemounts'))
+		{
+			die('Permission denied');
+		}
+
 		// Open download dialogue
 		if ($this->Input->get('download') && $this->strFile)
 		{
