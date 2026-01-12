# $NetBSD: Makefile,v 1.131 2026/01/12 22:20:30 gutteridge Exp $

PKGREVISION= 2
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=		xfce4-session-4.20.3
CATEGORIES=		x11
MASTER_SITES+=		https://archive.xfce.org/src/xfce/xfce4-session/${PKGVERSION_NOREV:R}/

HOMEPAGE=		https://docs.xfce.org/xfce/xfce4-session/start
COMMENT=		Xfce session manager

PKGCONFIG_OVERRIDE+=	libxfsm/xfce4-session-2.0.pc.in

BUILD_DEFS+=		PKG_SYSCONFBASE

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE}
CONFIGURE_ARGS+=	ICEAUTH=${TOOLS_PATH.iceauth}

USE_TOOLS+=		gdbus-codegen iceauth:run

EGDIR=			${XFCE4_EGBASE}
PKG_SYSCONFSUBDIR=	xdg

MAKE_DIRS+=	${PKG_SYSCONFDIR}
MAKE_DIRS+=	${EGDIR} ${EGDIR}/xfconf
MAKE_DIRS+=	${EGDIR}/xfconf/xfce-perchannel-xml

CONF_FILES=	${EGDIR}/xfconf/xfce-perchannel-xml/xfce4-session.xml	\
		${PKG_SYSCONFDIR}/xfce4/xfconf/xfce-perchannel-xml/xfce4-session.xml \
		${EGDIR}/Xft.xrdb					\
		${PKG_SYSCONFDIR}/xfce4/Xft.xrdb			\
		${EGDIR}/xinitrc					\
		${PKG_SYSCONFDIR}/xfce4/xinitrc

.if ${OPSYS} == Darwin
.include "../../sysutils/consolekit/buildlink3.mk"
.endif

.include "options.mk"

.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../devel/libwnck3/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libxfce4ui/buildlink3.mk"
.include "../../x11/libxfce4windowing/buildlink3.mk"
.include "../../x11/xscreensaver/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
