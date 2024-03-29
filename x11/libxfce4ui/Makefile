# $NetBSD: Makefile,v 1.43 2024/03/20 21:46:30 gutteridge Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	libxfce4ui-4.18.6
CATEGORIES=	x11
MASTER_SITES+=	https://archive.xfce.org/src/xfce/libxfce4ui/${PKGVERSION_NOREV:R}/

COMMENT=	Xfce widget library

BUILD_DEFS+=		PKG_SYSCONFBASE

CONFIGURE_ARGS+=	--enable-gtk3
CONFIGURE_ARGS=		--with-vendor-info=${OPSYS}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE}

PKG_SYSCONFSUBDIR=	xdg

PKGCONFIG_OVERRIDE=	libxfce4kbd-private/libxfce4kbd-private-2.pc.in
PKGCONFIG_OVERRIDE+=	libxfce4kbd-private/libxfce4kbd-private-3.pc.in
PKGCONFIG_OVERRIDE+=	libxfce4ui/libxfce4ui-1.pc.in
PKGCONFIG_OVERRIDE+=	libxfce4ui/libxfce4ui-2.pc.in

CONF_FILES=	${XFCE4_EGBASE}/xfconf/xfce-perchannel-xml/xfce4-keyboard-shortcuts.xml \
		${PKG_SYSCONFDIR}/xfce4/xfconf/xfce-perchannel-xml/xfce4-keyboard-shortcuts.xml

MAKE_DIRS+=	${XFCE4_EGBASE}/xfconf/xfce-perchannel-xml \
		${PKG_SYSCONFDIR}/xfce4/xfconf/xfce-perchannel-xml

USE_LANGUAGES=	c99

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/xfce4-conf/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/libxfce4util/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
