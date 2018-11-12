# $NetBSD: Makefile,v 1.34 2018/11/12 03:53:06 ryoon Exp $
#

DISTNAME=	ftmenu-0.3

PKGREVISION=	27
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ftmenu/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ftmenu.sourceforge.net/
COMMENT=	Fluxbox Tray Menu

GNU_CONFIGURE=		YES
LDFLAGS.DragonFly=	-lX11
LDFLAGS.SunOS+=		-lX11

#XXX: Not using C++, but configure require it.
USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/ftmenu
	${INSTALL_DATA} ${WRKSRC}/img/fb.xpm ${DESTDIR}${PREFIX}/share/ftmenu/fb.xpm

#XXX: Not using GLib, but configure require it.
BUILDLINK_TARGETS+=	glib-fake-pc

glib-fake-pc:
	${RUN}								\
	{ ${ECHO} "Name: GLib";						\
	${ECHO} "Description: C Utility Library";			\
	${ECHO} "Version: 1.2.10";					\
	${ECHO} "Libs:";						\
	${ECHO} "Cflags:";						\
	} > ${BUILDLINK_DIR}/lib/pkgconfig/glib.pc

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
