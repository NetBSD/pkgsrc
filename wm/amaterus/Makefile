# $NetBSD: Makefile,v 1.6 2002/08/25 21:51:26 jlam Exp $

DISTNAME=	amaterus-0.34.1
CATEGORIES=	wm
MASTER_SITES=	http://www.taiyaki.org/src/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.taiyaki.org/
COMMENT=	GTK+ window manager

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_X11=	YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/amaterus
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/amaterus
	${INSTALL_DATA} ${WRKSRC}/README.en ${PREFIX}/share/doc/amaterus

.include "../../textproc/libxml/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
