# $NetBSD: Makefile,v 1.4 2001/02/17 17:07:24 wiz Exp $

DISTNAME=	xscribble
PKGNAME=	xscribble-20000616
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.handhelds.org/pub/apps/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.handhelds.org/projects/xscribble.html
COMMENT=	Handwriting recognition (like graffiti)

USE_IMAKE=	YES
NO_INSTALL_MANPAGES=	YES

post-install:
	${MKDIR} ${PREFIX}/share/examples/xscribble
	${CP} ${WRKSRC}/classifiers/*.cl ${PREFIX}/share/examples/xscribble

.include "../../mk/bsd.pkg.mk"
