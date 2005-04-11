# $NetBSD: Makefile,v 1.14 2005/04/11 21:47:45 tv Exp $

DISTNAME=	amaterus-0.34.1
PKGREVISION=	4
CATEGORIES=	wm
MASTER_SITES=	http://www.taiyaki.org/src/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.taiyaki.org/
COMMENT=	GTK+ window manager

GNU_CONFIGURE=	YES
USE_X11=	YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/amaterus
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/amaterus
	${INSTALL_DATA} ${WRKSRC}/README.en ${PREFIX}/share/doc/amaterus

.include "../../textproc/libxml/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
