# $NetBSD: Makefile,v 1.54 2006/01/24 07:32:52 wiz Exp $
#

DISTNAME=		gnome-applets-2.12.2
PKGREVISION=		1
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-applets/2.12/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME2 panel applets

BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=		yes
USE_DIRS+=		gnome2-1.5
USE_MSGFMT_PLURALS=	yes
USE_TOOLS+=		gmake pkg-config
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnome2-applets
PKG_SUPPORTED_OPTIONS=	inet6
.include "../../mk/bsd.options.mk"

CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

PKGCONFIG_OVERRIDE+=	libgswitchit/gswitchit.pc.in

EGDIR=			${PREFIX}/share/examples/gnome-applets

GCONF2_SCHEMAS=		charpick.schemas
GCONF2_SCHEMAS+=	drivemount.schemas
GCONF2_SCHEMAS+=	geyes.schemas
GCONF2_SCHEMAS+=	gswitchit.schemas
GCONF2_SCHEMAS+=	gtik.schemas
GCONF2_SCHEMAS+=	gweather.schemas
GCONF2_SCHEMAS+=	mini-commander-global.schemas
GCONF2_SCHEMAS+=	mini-commander.schemas
GCONF2_SCHEMAS+=	mixer.schemas
GCONF2_SCHEMAS+=	multiload.schemas
GCONF2_SCHEMAS+=	stickynotes.schemas

.include "../../mk/bsd.prefs.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if ${OPSYS} == "Linux" || ${OPSYS} == "FreeBSD" || ${OPSYS} == "OpenBSD" || \
    (${OPSYS} == "NetBSD" && exists(/usr/include/machine/apmvar.h))
GCONF2_SCHEMAS+=	battstat.schemas
PLIST_SUBST+=		BATTSTAT=
CONF_FILES+=		${EGDIR}/sound/events/battstat_applet.soundlist \
			${PKG_SYSCONFDIR}/sound/events/battstat_applet.soundlist
.else
PLIST_SUBST+=		BATTSTAT="@comment "
CONFIGURE_ARGS+=	--disable-battstat
.endif

PRINT_PLIST_AWK+=	/[Bb]attstat/ { print "$${BATTSTAT}"$$0; next; }

.include "../../devel/GConf2/schemas.mk"

# This must come after GConf2's schemas.mk because it will modify default
# values for keys created during the registration of .schemas files.
INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL

BUILDLINK_DEPENDS.glib2+=	glib2>=2.6.0
BUILDLINK_DEPENDS.libglade2+=	libglade2>=2.4.0

.include "../../devel/gail/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../fonts/gucharmap/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/gstreamer0.8/buildlink3.mk"
.include "../../multimedia/gst-plugins0.8/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../sysutils/libgtop2/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/libxklavier/buildlink3.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
