# $NetBSD: Makefile,v 1.130 2024/05/16 06:15:46 wiz Exp $

PKGREVISION=	6
.include "../../meta-pkgs/xfce4/Makefile.common"

VERSION=	4.18.2
DISTNAME=	tumbler-${VERSION}
PKGNAME=	xfce4-tumbler-${VERSION}
CATEGORIES=	x11
MASTER_SITES=	https://archive.xfce.org/src/xfce/tumbler/${VERSION:R}/

HOMEPAGE=	https://docs.xfce.org/xfce/thunar/4.18/tumbler
COMMENT=	D-Bus thumbnailing service

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gdbus-codegen

CONFIGURE_ARGS=	--disable-raw-thumbnailer \
			--disable-gstreamer-thumbnailer

PKGCONFIG_OVERRIDE+=	tumbler/tumbler-1.pc.in

EGDIR=			${XFCE4_EGBASE}
PKG_SYSCONFSUBDIR=	xdg

MAKE_DIRS+=	${PKG_SYSCONFDIR}/tumbler

CONF_FILES=	${EGDIR}/tumbler.rc \
		${PKG_SYSCONFDIR}/tumbler/tumbler.rc

.include "options.mk"

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/libxfce4util/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
