# $NetBSD: Makefile,v 1.13 1999/04/26 19:30:26 garbled Exp $
# FreeBSD Id: Makefile,v 1.14 1997/09/14 04:00:00 jfitz Exp
#

DISTNAME=		Tk402.002
PKGNAME=		p5-Tk-402.002
CATEGORIES=		x11 tk80 perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Tk/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://theory.uwinnipeg.ca/CPAN/data/Tk/pod/overview.html

BUILD_DEPENDS= 		${PREFIX}/lib/perl5/site_perl/HTML/Parse.pm:../../www/p5-libwww
DEPENDS+=		tk-8.0.5:../../x11/tk80

USE_PERL5=		YES
USE_X11=		yes

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
