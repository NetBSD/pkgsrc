# $NetBSD: Makefile,v 1.10 1998/08/20 15:17:35 tsarna Exp $
# FreeBSD Id: Makefile,v 1.14 1997/09/14 04:00:00 jfitz Exp
#

DISTNAME=		Tk402.002
PKGNAME=		p5-Tk-402.002
CATEGORIES=		x11 tk80 perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Tk

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://theory.uwinnipeg.ca/CPAN/data/Tk/pod/overview.html

BUILD_DEPENDS= 		${PREFIX}/lib/perl5/site_perl/HTML/Parse.pm:../../www/p5-libwww
DEPENDS+=		tk-8.0p2:../../x11/tk80

USE_PERL5=		YES

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
