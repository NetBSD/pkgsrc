# $NetBSD: Makefile,v 1.37 2009/12/17 18:00:12 abs Exp $

DISTNAME=	wterm-6.2.9
PKGREVISION=	9
CATEGORIES=	x11 windowmaker
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wterm/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://wterm.sourceforge.net/
COMMENT=	NeXTStep(tm) style X11 terminal emulator for WindowMaker

GNU_CONFIGURE=	YES
USE_X11BASE=	YES

CONFIGURE_ARGS+= --enable-utmp --enable-wtmp
CONFIGURE_ARGS+= --enable-xpm-background --enable-transparency
CONFIGURE_ARGS+= --enable-menubar --enable-graphics --enable-next-scroll
CONFIGURE_ARGS+= --enable-half-shadow
CONFIGURE_ARGS+= --with-xpm-library=${BUILDLINK_PREFIX.libXpm}

PKG_DESTDIR_SUPPORT= destdir
INSTALLATION_DIRS+=  share/WindowMaker/Icons

post-install:
	${CHMOD} 4755 ${DESTDIR}${PREFIX}/bin/wterm
	${INSTALL_DATA} ${WRKSRC}/wterm.tiff \
		${DESTDIR}${PREFIX}/share/WindowMaker/Icons
	${INSTALL_DATA} ${WRKSRC}/wtermthai.tiff \
		${DESTDIR}${PREFIX}/share/WindowMaker/Icons

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../wm/windowmaker/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
