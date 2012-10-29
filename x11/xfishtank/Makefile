# $NetBSD: Makefile,v 1.17 2012/10/29 05:07:10 asau Exp $

DISTNAME=		xfishtank-2.2
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.uni-koeln.de/windows/xcontrib/

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Make fish swim in the background of your screen

WRKSRC=			${WRKDIR}/xfishtank2.0
USE_IMAKE=		yes
NO_INSTALL_MANPAGES=	yes

post-patch:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKEFLAGS} clean

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
