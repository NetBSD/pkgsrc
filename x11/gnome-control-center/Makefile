# $NetBSD: Makefile,v 1.100 2018/11/12 03:51:28 ryoon Exp $
#

DISTNAME=	gnome-control-center-2.32.1
PKGREVISION=	58
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-control-center/2.32/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/
COMMENT=	GNOME2 configuration utility
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LIBTOOL=		yes

CONFLICTS+=		gnome2-control-center-[0-9]* control-center-[0-9]*

CPPFLAGS+=		-DDBUS_API_SUBJECT_TO_CHANGE

PKGCONFIG_OVERRIDE+=	libwindow-settings/gnome-window-settings-2.0.pc.in

INSTALL_MAKE_FLAGS+=	${MAKE_FLAGS}
INSTALL_MAKE_FLAGS+=	vfsmoduleconfdir=${PREFIX}/share/examples/${PKGBASE}
INSTALL_MAKE_FLAGS+=	menudir=${PREFIX}/share/examples/${PKGBASE}
INSTALL_MAKE_FLAGS+=	autostartdir=${PREFIX}/share/applications

INSTALLATION_DIRS=	${EGDIR}

GCONF_SCHEMAS+=	control-center.schemas
GCONF_SCHEMAS+=	fontilus.schemas
GCONF_SCHEMAS+=	gnome-control-center.schemas

EGDIR=			${PREFIX}/share/examples/gnome-control-center
CONF_FILES+=		${EGDIR}/gnomecc.menu \
			${PKG_SYSCONFDIR}/xdg/menus/gnomecc.menu

.include "options.mk"

.include "../../audio/libcanberra/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
BUILDLINK_API_DEPENDS.glib2=	glib2>=2.8.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
BUILDLINK_API_DEPENDS.gstreamer0.10=		gstreamer0.10>=0.10.1.2
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
BUILDLINK_API_DEPENDS.gst-plugins0.10-base=	gst-plugins0.10-base>=0.10.1.2
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/gnome-menus/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../sysutils/nautilus/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../wm/metacity/buildlink3.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.8.12
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
BUILDLINK_API_DEPENDS.Xft2+=	Xft2>=2.1.2
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXxf86misc/buildlink3.mk"
BUILDLINK_API_DEPENDS.libxklavier=	libxklavier>=4.0
.include "../../x11/libxklavier/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgnomekbd2+= libgnomekbd2>=2.31.1
.include "../../x11/libgnomekbd2/buildlink3.mk"
.include "../../x11/libunique/buildlink3.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../sysutils/gnome-settings-daemon/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
