# $NetBSD: Makefile,v 1.22 2001/10/02 06:39:59 jlam Exp $
# FreeBSD Id: Makefile,v 1.14 1997/09/14 04:00:00 jfitz Exp
#

DISTNAME=		Tk800.022
PKGNAME=		p5-Tk-800.022
CATEGORIES=		x11 tk perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Tk/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://theory.uwinnipeg.ca/CPAN/data/Tk/pod/overview.html
COMMENT=		perl5 interface to Tk

BUILD_DEPENDS= 		p5-HTML-Parser>=3.19:../../www/p5-HTML-Parser

USE_X11=		# defined
USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Tk/.packlist

MAKE_PARAMS=		X11=${X11BASE}

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL ${MAKE_PARAMS}

.include "../../x11/tk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
