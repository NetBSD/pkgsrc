# $NetBSD: Makefile,v 1.1.1.1 2001/06/28 16:15:17 wiz Exp $

DISTNAME=	amaterus-0.34.1
CATEGORIES=	wm
MASTER_SITES=	http://www.taiyaki.org/src/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.taiyaki.org/
COMMENT=	GTK+ window manager

GNU_CONFIGURE=		YES
USE_BUILDLINK_ONLY=	YES
USE_CONFIG_WRAPPER=	YES
USE_X11=		YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/amaterus
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/amaterus
	${INSTALL_DATA} ${WRKSRC}/README.en ${PREFIX}/share/doc/amaterus

.include "../../textproc/libxml/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
