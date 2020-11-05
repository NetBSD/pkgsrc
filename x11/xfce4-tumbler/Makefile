# $NetBSD: Makefile,v 1.90 2020/11/05 09:09:29 ryoon Exp $

PKGREVISION= 2
.include "../../meta-pkgs/xfce4/Makefile.common"

VERSION=	0.3.0
DISTNAME=	tumbler-${VERSION}
PKGNAME=	xfce4-tumbler-${VERSION}
CATEGORIES=	x11
MASTER_SITES=	https://archive.xfce.org/src/xfce/tumbler/${VERSION:R}/

HOMEPAGE=	https://docs.xfce.org/xfce/thunar/tumbler
COMMENT=	D-Bus thumbnailing service

TOOL_DEPENDS+=	gdbus-codegen-[0-9]*:../../devel/gdbus-codegen

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

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
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
