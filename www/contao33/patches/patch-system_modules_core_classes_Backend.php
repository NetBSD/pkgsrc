$NetBSD: patch-system_modules_core_classes_Backend.php,v 1.1.2.1 2015/02/14 10:07:52 tron Exp $

Fix for CVE-2015-0269.

--- system/modules/core/classes/Backend.php.orig	2014-11-24 09:12:58.000000000 +0000
+++ system/modules/core/classes/Backend.php
@@ -662,6 +662,8 @@ abstract class Backend extends \Controll
 	 * Add a breadcrumb menu to the page tree
 	 *
 	 * @param string
+	 *
+	 * @throws \RuntimeException
 	 */
 	public static function addPagesBreadcrumb($strKey='tl_page_node')
 	{
@@ -670,7 +672,13 @@ abstract class Backend extends \Controll
 		// Set a new node
 		if (isset($_GET['node']))
 		{
-			$objSession->set($strKey, \Input::get('node'));
+			// Check the path (thanks to Arnaud Buchoux)
+			if (\Validator::isInsecurePath(\Input::get('node', true)))
+			{
+				throw new \RuntimeException('Insecure path ' . \Input::get('node', true));
+			}
+
+			$objSession->set($strKey, \Input::get('node', true));
 			\Controller::redirect(preg_replace('/&node=[^&]*/', '', \Environment::get('request')));
 		}
 
@@ -681,6 +689,12 @@ abstract class Backend extends \Controll
 			return;
 		}
 
+		// Check the path (thanks to Arnaud Buchoux)
+		if (\Validator::isInsecurePath($intNode))
+		{
+			throw new \RuntimeException('Insecure path ' . $intNode);
+		}
+
 		$arrIds   = array();
 		$arrLinks = array();
 		$objUser  = \BackendUser::getInstance();
@@ -800,6 +814,8 @@ abstract class Backend extends \Controll
 	 * Add a breadcrumb menu to the file tree
 	 *
 	 * @param string
+	 *
+	 * @throws \RuntimeException
 	 */
 	public static function addFilesBreadcrumb($strKey='tl_files_node')
 	{
@@ -808,6 +824,12 @@ abstract class Backend extends \Controll
 		// Set a new node
 		if (isset($_GET['node']))
 		{
+			// Check the path (thanks to Arnaud Buchoux)
+			if (\Validator::isInsecurePath(\Input::get('node', true)))
+			{
+				throw new \RuntimeException('Insecure path ' . \Input::get('node', true));
+			}
+
 			$objSession->set($strKey, \Input::get('node', true));
 			\Controller::redirect(preg_replace('/(&|\?)node=[^&]*/', '', \Environment::get('request')));
 		}
@@ -819,6 +841,12 @@ abstract class Backend extends \Controll
 			return;
 		}
 
+		// Check the path (thanks to Arnaud Buchoux)
+		if (\Validator::isInsecurePath($strNode))
+		{
+			throw new \RuntimeException('Insecure path ' . $strNode);
+		}
+
 		// Currently selected folder does not exist
 		if (!is_dir(TL_ROOT . '/' . $strNode))
 		{
