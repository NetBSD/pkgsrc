# $NetBSD: Makefile,v 1.20 2001/05/05 19:51:20 jlam Exp $
# FreeBSD Id: Makefile,v 1.14 1997/09/14 04:00:00 jfitz Exp
#

DISTNAME=		Tk800.022
PKGNAME=		p5-Tk-800.022
CATEGORIES=		x11 tk perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Tk/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://theory.uwinnipeg.ca/CPAN/data/Tk/pod/overview.html
COMMENT=		perl5 interface to Tk-8.0.5

BUILD_DEPENDS= 		p5-HTML-Parser-3.19:../../www/p5-HTML-Parser
DEPENDS+=		tk>=8.3.2:../../x11/tk

USE_X11=		# defined
USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Tk/.packlist

MAKE_PARAMS=		X11=${X11BASE}

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL ${MAKE_PARAMS}

.include "../../mk/bsd.pkg.mk"
