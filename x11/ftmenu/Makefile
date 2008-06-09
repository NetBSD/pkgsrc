# $NetBSD: Makefile,v 1.2 2008/06/09 15:27:03 obache Exp $
#

DISTNAME=	ftmenu-0.3

CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ftmenu/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ftmenu.sourceforge.net/
COMMENT=	Fluxbox Tray Menu

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES

USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/ftmenu
	${INSTALL_DATA} ${WRKSRC}/img/fb.xpm ${DESTDIR}${PREFIX}/share/ftmenu/fb.xpm

#XXX: This package not using glib, but ckeck it.
BUILDLINK_TARGETS+=	glib-fake-pc

glib-fake-pc:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	{ ${ECHO} "Name: GLib";						\
	${ECHO} "Description: C Utility Library";			\
	${ECHO} "Version: 1.2.10";					\
	${ECHO} "Libs:";						\
	${ECHO} "Cflags:";						\
	} > ${BUILDLINK_DIR}/lib/pkgconfig/glib.pc

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
