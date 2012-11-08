$NetBSD: patch-system_modules_calendar_modules_ModuleCalendar.php,v 1.1 2012/11/08 04:56:02 taca Exp $

Appply 995f0d323234e038f5357ee87e78586730f4e2fd to fix class assignment
of calendar from the repository <https://github.com/contao/core/>.

--- system/modules/calendar/modules/ModuleCalendar.php.orig	2012-10-30 08:24:57.000000000 +0000
+++ system/modules/calendar/modules/ModuleCalendar.php
@@ -179,7 +179,7 @@ class ModuleCalendar extends \Events
 		for ($i=0; $i<7; $i++)
 		{
 			$intCurrentDay = ($i + $this->cal_startDay) % 7;
-			$arrDays[$intCurrentDay] = $GLOBALS['TL_LANG']['DAYS'][$intCurrentDay];
+			$arrDays[$i] = $GLOBALS['TL_LANG']['DAYS'][$intCurrentDay];
 		}
 
 		return $arrDays;
