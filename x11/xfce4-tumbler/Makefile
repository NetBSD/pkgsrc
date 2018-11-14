# $NetBSD: Makefile,v 1.52 2018/11/14 22:22:53 kleink Exp $

PKGREVISION= 8
.include "../../meta-pkgs/xfce4/Makefile.common"

VERSION=	0.2.1
DISTNAME=	tumbler-${VERSION}
PKGNAME=	xfce4-tumbler-${VERSION}
CATEGORIES=	x11
MASTER_SITES=	http://archive.xfce.org/src/xfce/tumbler/0.2/

HOMEPAGE=	http://docs.xfce.org/xfce/thunar/tumbler
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

INSTALL_UNSTRIPPED=	yes
CFLAGS+=		-g

.include "options.mk"

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../multimedia/ffmpeg3/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
