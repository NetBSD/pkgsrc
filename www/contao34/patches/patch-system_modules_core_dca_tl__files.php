$NetBSD: patch-system_modules_core_dca_tl__files.php,v 1.1.2.2 2015/06/12 22:44:26 tron Exp $

Security improvement as Contao 3.2.21.

--- system/modules/core/dca/tl_files.php.orig	2015-03-27 08:53:59.000000000 +0000
+++ system/modules/core/dca/tl_files.php
@@ -488,7 +488,7 @@ class tl_files extends Backend
 	 */
 	public function editFile($row, $href, $label, $title, $icon, $attributes)
 	{
-		return $this->User->hasAccess('f2', 'fop') ? '<a href="'.$this->addToUrl($href.'&amp;id='.$row['id']).'" title="'.specialchars($title).'"'.$attributes.'>'.Image::getHtml($icon, $label).'</a> ' : Image::getHtml(preg_replace('/\.gif$/i', '_.gif', $icon)).' ';
+		return ($this->User->isAdmin || $this->User->hasAccess('f2', 'fop')) ? '<a href="'.$this->addToUrl($href.'&amp;id='.$row['id']).'" title="'.specialchars($title, false, true).'"'.$attributes.'>'.Image::getHtml($icon, $label).'</a> ' : Image::getHtml(preg_replace('/\.gif$/i', '_.gif', $icon)).' ';
 	}
 
 
@@ -504,7 +504,7 @@ class tl_files extends Backend
 	 */
 	public function copyFile($row, $href, $label, $title, $icon, $attributes)
 	{
-		return $this->User->hasAccess('f2', 'fop') ? '<a href="'.$this->addToUrl($href.'&amp;id='.$row['id']).'" title="'.specialchars($title).'"'.$attributes.'>'.Image::getHtml($icon, $label).'</a> ' : Image::getHtml(preg_replace('/\.gif$/i', '_.gif', $icon)).' ';
+		return ($this->User->isAdmin || $this->User->hasAccess('f2', 'fop')) ? '<a href="'.$this->addToUrl($href.'&amp;id='.$row['id']).'" title="'.specialchars($title, false, true).'"'.$attributes.'>'.Image::getHtml($icon, $label).'</a> ' : Image::getHtml(preg_replace('/\.gif$/i', '_.gif', $icon)).' ';
 	}
 
 
@@ -520,7 +520,7 @@ class tl_files extends Backend
 	 */
 	public function cutFile($row, $href, $label, $title, $icon, $attributes)
 	{
-		return $this->User->hasAccess('f2', 'fop') ? '<a href="'.$this->addToUrl($href.'&amp;id='.$row['id']).'" title="'.specialchars($title).'"'.$attributes.'>'.Image::getHtml($icon, $label).'</a> ' : Image::getHtml(preg_replace('/\.gif$/i', '_.gif', $icon)).' ';
+		return ($this->User->isAdmin || $this->User->hasAccess('f2', 'fop')) ? '<a href="'.$this->addToUrl($href.'&amp;id='.$row['id']).'" title="'.specialchars($title, false, true).'"'.$attributes.'>'.Image::getHtml($icon, $label).'</a> ' : Image::getHtml(preg_replace('/\.gif$/i', '_.gif', $icon)).' ';
 	}
 
 
@@ -538,11 +538,11 @@ class tl_files extends Backend
 	{
 		if (is_dir(TL_ROOT . '/' . $row['id']) && count(scan(TL_ROOT . '/' . $row['id'])) > 0)
 		{
-			return $this->User->hasAccess('f4', 'fop') ? '<a href="'.$this->addToUrl($href.'&amp;id='.$row['id']).'" title="'.specialchars($title).'"'.$attributes.'>'.Image::getHtml($icon, $label).'</a> ' : Image::getHtml(preg_replace('/\.gif$/i', '_.gif', $icon)).' ';
+			return ($this->User->isAdmin || $this->User->hasAccess('f4', 'fop')) ? '<a href="'.$this->addToUrl($href.'&amp;id='.$row['id']).'" title="'.specialchars($title, false, true).'"'.$attributes.'>'.Image::getHtml($icon, $label).'</a> ' : Image::getHtml(preg_replace('/\.gif$/i', '_.gif', $icon)).' ';
 		}
 		else
 		{
-			return ($this->User->hasAccess('f3', 'fop') || $this->User->hasAccess('f4', 'fop')) ? '<a href="'.$this->addToUrl($href.'&amp;id='.$row['id']).'" title="'.specialchars($title).'"'.$attributes.'>'.Image::getHtml($icon, $label).'</a> ' : Image::getHtml(preg_replace('/\.gif$/i', '_.gif', $icon)).' ';
+			return ($this->User->isAdmin || $this->User->hasAccess('f3', 'fop') || $this->User->hasAccess('f4', 'fop')) ? '<a href="'.$this->addToUrl($href.'&amp;id='.$row['id']).'" title="'.specialchars($title, false, true).'"'.$attributes.'>'.Image::getHtml($icon, $label).'</a> ' : Image::getHtml(preg_replace('/\.gif$/i', '_.gif', $icon)).' ';
 		}
 	}
 
@@ -578,7 +578,7 @@ class tl_files extends Backend
 			return Image::getHtml(preg_replace('/\.gif$/i', '_.gif', $icon)).' ';
 		}
 
-		return '<a href="'.$this->addToUrl($href.'&amp;id='.$row['id']).'" title="'.specialchars($title).'"'.$attributes.'>'.Image::getHtml($icon, $label).'</a> ';
+		return '<a href="'.$this->addToUrl($href.'&amp;id='.$row['id']).'" title="'.specialchars($title, false, true).'"'.$attributes.'>'.Image::getHtml($icon, $label).'</a> ';
 	}
 
 
@@ -600,7 +600,7 @@ class tl_files extends Backend
 		}
 		else
 		{
-			return '<a href="contao/popup.php?src=' . base64_encode($row['id']) . '" title="'.specialchars($title).'"'.$attributes.' onclick="Backend.openModalIframe({\'width\':'.$row['popupWidth'].',\'title\':\''.str_replace("'", "\\'", $row['fileNameEncoded']).'\',\'url\':this.href,\'height\':'.$row['popupHeight'].'});return false">'.Image::getHtml($icon, $label).'</a> ';
+			return '<a href="contao/popup.php?src=' . base64_encode($row['id']) . '" title="'.specialchars($title, false, true).'"'.$attributes.' onclick="Backend.openModalIframe({\'width\':'.$row['popupWidth'].',\'title\':\''.str_replace("'", "\\'", $row['fileNameEncoded']).'\',\'url\':this.href,\'height\':'.$row['popupHeight'].'});return false">'.Image::getHtml($icon, $label).'</a> ';
 		}
 	}
 
