# $NetBSD: Makefile,v 1.103 2012/09/07 19:17:43 adam Exp $
#

DISTNAME=		gnome-applets-2.32.1.1
PKGREVISION=		16
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-applets/2.32/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME2 panel applets

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes

.include "options.mk"

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
# obsolete; replaced by PA mixer in gnome-media>=2.26
CONFIGURE_ARGS+=	--enable-mixer-applet
# obsolete; replaced by gnome-power-manager>=2.24
CONFIGURE_ARGS+=	--disable-cpufreq

EGDIR=			${PREFIX}/share/examples/gnome-applets

GCONF_SCHEMAS=		charpick.schemas
GCONF_SCHEMAS+=	drivemount.schemas
GCONF_SCHEMAS+=	geyes.schemas
#GCONF_SCHEMAS+=	gswitchit.schemas
GCONF_SCHEMAS+=	mixer.schemas
GCONF_SCHEMAS+=	multiload.schemas
GCONF_SCHEMAS+=	stickynotes.schemas

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=		battstat
.if ${OPSYS} == "Linux" || ${OPSYS} == "FreeBSD" || ${OPSYS} == "OpenBSD" || \
    (${OPSYS} == "NetBSD" && exists(/usr/include/machine/apmvar.h))
GCONF_SCHEMAS+=	battstat.schemas
PLIST.battstat=		yes
CONF_FILES+=		${EGDIR}/sound/events/battstat_applet.soundlist \
			${PKG_SYSCONFDIR}/sound/events/battstat_applet.soundlist
.else
CONFIGURE_ARGS+=	--disable-battstat
.endif

PRINT_PLIST_AWK+=	/[Bb]attstat/ { print "$${PLIST.battstat}"$$0; next; }
PRINT_PLIST_AWK+=	/examples/ { print "$${PLIST.battstat}"$$0; next; }

.include "../../devel/GConf/schemas.mk"

PY_PATCHPLIST=	yes
PYTHON_PATCH_SCRIPTS+=	invest-applet/invest/invest-applet.py
PYTHON_PATCH_SCRIPTS+=	invest-applet/invest/invest-chart

.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=			glib2>=2.18.0
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgweather+=	libgweather>=2.22.1
.include "../../devel/libgweather/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../fonts/gucharmap/buildlink3.mk"
BUILDLINK_API_DEPENDS.gnome-icon-theme+=	gnome-icon-theme>=2.15.91
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/omf-scrollkeeper.mk"
BUILDLINK_API_DEPENDS.gst-plugins0.10-base+=	gst-plugins0.10-base>=0.10.2
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
BUILDLINK_API_DEPENDS.gstreamer0.10+=		gstreamer0.10>=0.10.2
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
BUILDLINK_API_DEPENDS.dbus+=	dbus>=1.1.2
.include "../../sysutils/dbus/buildlink3.mk"
BUILDLINK_API_DEPENDS.dbus-glib+=	dbus-glib>=0.74
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/gnome-settings-daemon/buildlink3.mk"
.include "../../sysutils/libgtop/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../x11/gnome-control-center/buildlink3.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
BUILDLINK_API_DEPENDS.gnome-panel+=	gnome-panel>=2.31.2
.include "../../x11/gnome-panel/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=			gtk2+>=2.13.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libgnomekbd/buildlink3.mk"
.include "../../x11/libxklavier/buildlink3.mk"
.include "../../x11/py-gnome2-desktop/buildlink3.mk"
.include "../../x11/py-gnome2/buildlink3.mk"

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
