# $NetBSD: Makefile,v 1.27 2001/11/28 12:22:35 martti Exp $
# FreeBSD Id: Makefile,v 1.14 1997/09/14 04:00:00 jfitz Exp
#

DISTNAME=		Tk800.023
PKGNAME=		p5-Tk-800.023
SVR4_PKGNAME=		p5tk
CATEGORIES=		x11 tk perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Tk/}

MAINTAINER=		shell@shellhung.org
HOMEPAGE=		http://theory.uwinnipeg.ca/CPAN/data/Tk/pod/overview.html
COMMENT=		perl5 interface to Tk

BUILD_DEPENDS= 		p5-HTML-Parser>=3.19:../../www/p5-HTML-Parser

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Tk/.packlist

MAKE_PARAMS=		X11=${BUILDLINK_X11_DIR}

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL ${MAKE_PARAMS}

.include "../../lang/perl5/buildlink.mk"
.include "../../x11/tk/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
