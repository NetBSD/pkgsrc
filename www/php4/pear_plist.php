<?php
# $NetBSD: pear_plist.php,v 1.1 2004/04/03 04:39:47 jdolecek Exp $
# Parses package XML file and outputs appropriate PLIST

$PEAR_LIB = getenv('PEAR_LIB');
$WRKSRC = getenv('WRKSRC');
$PEAR_DIRRM_BASEDIR = getenv('PEAR_DIRRM_BASEDIR');
$dirrm = array();

include_once "PEAR/Common.php";
$obj = &new PEAR_Common;
$info = $obj->infoFromAny("$WRKSRC/package.xml");
$pkg = $info['package'];

// output list of package files, in same order as specified in package
echo "$PEAR_LIB/.registry/".strtolower($pkg).".reg\n";
foreach($info['filelist'] as $f => $v) {
	switch($v['role']) {
	case 'test':
	case 'doc':
		$prefix = "$v[role]/$pkg/";
		$dirrm["$v[role]/$pkg"] = true;
		break;

	case 'php':
	default:
		if (!empty($v['baseinstalldir']) && $v['baseinstalldir'] != '/') {
			$prefix = $v['baseinstalldir'] . '/';

			if ($PEAR_DIRRM_BASEDIR)
				$dirrm[$v['baseinstalldir']] = true;
		} else
			$prefix = '';
		break;
	}


	echo "{$PEAR_LIB}/{$prefix}{$f}\n";

	while(($f = dirname($f)) && $f != '.')
		$dirrm["{$prefix}{$f}"] = true;
}

// output @dirrm directives, in reverse order so that deeper
// directories are removed first
$dirrm = array_keys($dirrm);
rsort($dirrm);
foreach($dirrm as $dir)
	echo "@dirrm {$PEAR_LIB}/$dir\n";
?>
