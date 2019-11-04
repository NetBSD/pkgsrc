# $NetBSD: Makefile,v 1.23 2019/11/04 21:50:15 rillig Exp $

DISTNAME=	amaterus-0.34.1
PKGREVISION=	6
CATEGORIES=	wm
MASTER_SITES=	http://www.taiyaki.org/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.taiyaki.org/
COMMENT=	GTK+ window manager

GNU_CONFIGURE=		YES
INSTALLATION_DIRS=	share/doc/amaterus

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/amaterus
	${INSTALL_DATA} ${WRKSRC}/README.en ${DESTDIR}${PREFIX}/share/doc/amaterus

.include "../../textproc/libxml/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
