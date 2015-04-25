# $NetBSD: Makefile,v 1.50 2015/04/25 14:25:25 tnn Exp $

PKGREVISION= 1
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=		xfce4-session-4.10.1
CATEGORIES=		x11
MASTER_SITES+=		http://archive.xfce.org/src/xfce/xfce4-session/4.10/

HOMEPAGE=	http://docs.xfce.org/xfce/xfce4-session/start
COMMENT=		Xfce session manager

PKGCONFIG_OVERRIDE+=	libxfsm/xfce4-session-2.0.pc.in

BUILD_DEFS+=		PKG_SYSCONFBASE

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE}
CONFIGURE_ARGS+=	ICEAUTH=${TOOLS_PATH.iceauth}

USE_TOOLS+=		iceauth:run

EGDIR=			${XFCE4_EGBASE}
PKG_SYSCONFSUBDIR=	xdg

MAKE_DIRS+=	${PKG_SYSCONFDIR} ${PKG_SYSCONFDIR}/autostart
MAKE_DIRS+=	${PREFIX}/include/xfce4 ${PREFIX}/lib/xfce4
MAKE_DIRS+=	${EGDIR} ${EGDIR}/autostart ${EGDIR}/xfconf
MAKE_DIRS+=	${EGDIR}/xfconf/xfce-perchannel-xml
MAKE_DIRS+=	${EGDIR}/share/themes/Default
MAKE_DIRS+=	${PREFIX}/share/xfce4 ${PREFIX}/share/xfce4/doc
MAKE_DIRS+=	${PREFIX}/share/xfce4/doc/C ${PREFIX}/share/xfce4/doc/C/images
MAKE_DIRS+=	${PREFIX}/share/xfce4/doc/fr ${PREFIX}/share/xfce4/doc/fr/images

#CONF_FILES=	${EGDIR}/applications/xfce-session-settings.desktop \
		${PKG_SYSCONFDIR}/applications/xfce-session-settings.desktop
#CONF_FILES+=	${EGDIR}/applications/xfce4-session-logout.desktop \
		${PKG_SYSCONFDIR}/applications/xfce4-session-logout.desktop
CONF_FILES=	${EGDIR}/autostart/xscreensaver.desktop \
		${PKG_SYSCONFDIR}/autostart/xscreensaver.desktop
CONF_FILES=	${EGDIR}/xfconf/xfce-perchannel-xml/xfce4-session.xml \
		${PKG_SYSCONFDIR}/xfce4/xfconf/xfce-perchannel-xml/xfce4-session.xml
CONF_FILES+=	${EGDIR}/Xft.xrdb \
		${PKG_SYSCONFDIR}/xfce4/Xft.xrdb
CONF_FILES+=	${EGDIR}/xinitrc \
		${PKG_SYSCONFDIR}/xfce4/xinitrc

.if !empty(Darwin-*-*)
.include "../../sysutils/consolekit/buildlink3.mk"
.endif

.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../security/policykit/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libxfce4ui/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
