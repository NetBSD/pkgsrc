<?php

// $NetBSD: downstream.php,v 1.1 2019/03/15 16:32:13 hauke Exp $
//
// pkgsrc GLPI path setup file, see
// <http://glpi-developer-documentation.readthedocs.io/en/master/packaging.html>

// Configuration
define('GLPI_CONFIG_DIR',	'@PKG_SYSCONFDIR@');

if (file_exists(GLPI_CONFIG_DIR . '/local_define.php')) {
   require_once GLPI_CONFIG_DIR . '/local_define.php';
}
