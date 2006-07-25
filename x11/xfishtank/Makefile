# $NetBSD: Makefile,v 1.14 2006/07/25 15:58:28 jlam Exp $

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

.include "../../mk/bsd.pkg.mk"
