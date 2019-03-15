<?php

// $NetBSD: local_define.php,v 1.1 2019/03/15 16:32:13 hauke Exp $
//
// pkgsrc GLPI setup file, see
// <http://glpi-developer-documentation.readthedocs.io/en/master/packaging.html>

// Configuration
define('GLPI_CONFIG_DIR',	'@PKG_SYSCONFDIR@');

// Runtime Data
define('GLPI_VAR_DIR',		'@VARBASE@/glpi');

// Log file
define('GLPI_LOG_DIR',		'@VARBASE@/log/glpi');

// System libraries
//  htmlawed not in pkgsrc - built-in, anyway?
//define('GLPI_HTMLAWED',	'@PREFIX@/share/php/htmLawed/htmLawed.php');

// Fonts
//  fonts/freefont-ttf
define('GLPI_FONT_FREESANS',	'@PREFIX@/share/fonts/X11/TTF/FreeSans.ttf');

// Use system cron
define('GLPI_SYSTEM_CRON', true);
