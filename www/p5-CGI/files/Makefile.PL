# $NetBSD: Makefile.PL,v 1.2 2000/08/28 23:06:00 jlam Exp $
use ExtUtils::MakeMaker;
# See lib/ExtUtils/MakeMaker.pm for details of how to influence
# the contents of the Makefile that is written.
WriteMakefile(
    'NAME'		=> 'CGI',
    'DISTNAME'		=> 'CGI.pm',
    'VERSION_FROM'	=> 'CGI.pm',
    'linkext'		=> { LINKTYPE=>'' },	# no link needed
    'dist'		=> {'COMPRESS'=>'gzip -9f', 'SUFFIX' => 'gz'}
);
