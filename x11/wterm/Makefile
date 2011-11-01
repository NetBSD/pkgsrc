# $NetBSD: Makefile,v 1.44 2011/11/01 06:03:10 sbd Exp $

DISTNAME=	wterm-6.2.9
PKGREVISION=	15
CATEGORIES=	x11 windowmaker
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wterm/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://wterm.sourceforge.net/
COMMENT=	NeXTStep(tm) style X11 terminal emulator for WindowMaker

PKG_DESTDIR_SUPPORT= user-destdir
MAKE_JOBS_SAFE=	no

GNU_CONFIGURE=	YES
USE_X11BASE=	YES

CONFIGURE_ARGS+= --enable-utmp --enable-wtmp
CONFIGURE_ARGS+= --enable-xpm-background --enable-transparency
CONFIGURE_ARGS+= --enable-menubar --enable-graphics --enable-next-scroll
CONFIGURE_ARGS+= --enable-half-shadow
CONFIGURE_ARGS+= --with-xpm-library=${BUILDLINK_PREFIX.libXpm}

INSTALLATION_DIRS+=  share/WindowMaker/Icons

post-install:
	${INSTALL_DATA} ${WRKSRC}/wterm.tiff \
		${DESTDIR}${PREFIX}/share/WindowMaker/Icons
	${INSTALL_DATA} ${WRKSRC}/wtermthai.tiff \
		${DESTDIR}${PREFIX}/share/WindowMaker/Icons

SPECIAL_PERMS+=	bin/wterm ${SETUID_ROOT_PERMS}

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../wm/windowmaker/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
