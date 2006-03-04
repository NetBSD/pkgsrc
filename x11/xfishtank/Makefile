# $NetBSD: Makefile,v 1.13 2006/03/04 21:31:12 jlam Exp $

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
	cd ${WRKDIR}/xfishtank2.0; ${MAKE} clean

.include "../../mk/bsd.pkg.mk"
