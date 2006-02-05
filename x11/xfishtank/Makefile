# $NetBSD: Makefile,v 1.12 2006/02/05 23:11:47 joerg Exp $

DISTNAME=		xfishtank-2.2
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.uni-koeln.de/windows/xcontrib/

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Make fish swim in the background of your screen

WRKSRC=			${WRKDIR}/xfishtank2.0
USE_IMAKE=		yes
NO_INSTALL_MANPAGES=	yes

post-patch:
	cd ${WRKDIR}/xfishtank2.0; ${MAKE} clean

.include "../../mk/bsd.pkg.mk"
