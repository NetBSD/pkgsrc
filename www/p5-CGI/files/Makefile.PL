# $NetBSD: Makefile.PL,v 1.1 2000/05/11 20:04:04 christos Exp $
use ExtUtils::MakeMaker;
# See lib/ExtUtils/MakeMaker.pm for details of how to influence
# the contents of the Makefile that is written.
WriteMakefile(
    'NAME'	=> 'CGI',
    'DISTNAME'  => 'CGI.pm',
    'VERSION'   => '2.66',
    'linkext'   => { LINKTYPE=>'' },	# no link needed
    'dist'      => {'COMPRESS'=>'gzip -9f', 'SUFFIX' => 'gz'}
);
