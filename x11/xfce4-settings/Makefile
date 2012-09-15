# $NetBSD: Makefile,v 1.17 2012/09/15 10:07:20 obache Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=		4.6.5

DISTNAME=		xfce4-settings-${XFCE4_VERSION}
PKGREVISION=		12
CATEGORIES=		x11
COMMENT=		Xfce settings manager

MASTER_SITES+=		http://archive.xfce.org/src/xfce/xfce4-settings/4.6/

BUILD_DEFS+=		PKG_SYSCONFBASE

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE}

EGDIR=			${XFCE4_EGBASE}/xfconf/xfce-perchannel-xml
PKG_SYSCONFSUBDIR=	xdg

MAKE_DIRS+=	${XFCE4_EGBASE:Q} ${XFCE4_EGBASE:Q}/xfconf ${EGDIR}

CONF_FILES=	${EGDIR}/xsettings.xml \
	${PKG_SYSCONFDIR}/xfce4/xfconf/xfce-perchannel-xml/xsettings.xml

CONF_FILES+=	\
	${XFCE4_EGBASE:Q}/autostart/xfce4-settings-helper-autostart.desktop \
	${PKG_SYSCONFDIR}/autostart/xfce4-settings-helper-autostart.desktop

.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../devel/xfconf/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libxfce4gui/buildlink3.mk"
.include "../../x11/libxfce4util/buildlink3.mk"
.include "../../x11/libxklavier/buildlink3.mk"
.include "../../x11/xfce4-exo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
