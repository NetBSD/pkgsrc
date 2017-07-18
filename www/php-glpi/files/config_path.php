<?php

// $NetBSD: config_path.php,v 1.1 2017/07/18 14:29:51 hauke Exp $
//
// pkgsrc GLPI path setup file

// Configuration
define('GLPI_CONFIG_DIR',	'@PKG_SYSCONFDIR@');

// Runtime Data
define('GLPI_DOC_DIR',		'@VARBASE@/glpi');
define('GLPI_CRON_DIR',		GLPI_DOC_DIR . '/_cron');
define('GLPI_DUMP_DIR',		GLPI_DOC_DIR . '/_dumps');
define('GLPI_GRAPH_DIR',	GLPI_DOC_DIR . '/_graphs');
define('GLPI_LOCK_DIR',		GLPI_DOC_DIR . '/_lock');
define('GLPI_PICTURE_DIR',	GLPI_DOC_DIR . '/_pictures');
define('GLPI_PLUGIN_DOC_DIR',	GLPI_DOC_DIR . '/_plugins');
define('GLPI_RSS_DIR',		GLPI_DOC_DIR . '/_rss');
define('GLPI_SESSION_DIR',	GLPI_DOC_DIR . '/_sessions');
define('GLPI_TMP_DIR',		GLPI_DOC_DIR . '/_tmp');
define('GLPI_UPLOAD_DIR',	GLPI_DOC_DIR . '/_uploads');

// Log file
define('GLPI_LOG_DIR',        '@VARBASE@/log/glpi');

// System libraries
//  htmlawed not in pkgsrc - built-in, anyway?
//define('GLPI_HTMLAWED',	'@PREFIX@/share/php/htmLawed/htmLawed.php');

// Fonts
//  fonts/freefont-ttf
define('GLPI_FONT_FREESANS',	'@PREFIX@/share/fonts/X11/TTF/FreeSans.ttf');

// Use system cron
define('GLPI_SYSTEM_CRON', true);
