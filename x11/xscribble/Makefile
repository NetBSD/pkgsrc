# $NetBSD: Makefile,v 1.7 2003/07/17 22:57:03 grant Exp $

DISTNAME=	xscribble
PKGNAME=	xscribble-20000616
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.handhelds.org/pub/apps/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.handhelds.org/projects/xscribble.html
COMMENT=	Handwriting recognition (like graffiti)

USE_IMAKE=	YES
NO_INSTALL_MANPAGES=	YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/xscribble
	${INSTALL_DATA} ${WRKSRC}/classifiers/*.cl ${PREFIX}/share/examples/xscribble

.include "../../mk/bsd.pkg.mk"
