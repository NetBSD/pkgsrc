# $NetBSD: Makefile,v 1.17 2006/03/04 21:30:54 jlam Exp $

DISTNAME=	amaterus-0.34.1
PKGREVISION=	5
CATEGORIES=	wm
MASTER_SITES=	http://www.taiyaki.org/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
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
