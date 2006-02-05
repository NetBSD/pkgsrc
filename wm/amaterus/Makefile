# $NetBSD: Makefile,v 1.16 2006/02/05 23:11:12 joerg Exp $

DISTNAME=	amaterus-0.34.1
PKGREVISION=	5
CATEGORIES=	wm
MASTER_SITES=	http://www.taiyaki.org/src/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.taiyaki.org/
COMMENT=	GTK+ window manager

GNU_CONFIGURE=	YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/amaterus
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/amaterus
	${INSTALL_DATA} ${WRKSRC}/README.en ${PREFIX}/share/doc/amaterus

.include "../../textproc/libxml/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
