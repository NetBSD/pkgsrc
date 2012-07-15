# $NetBSD: Makefile,v 1.48 2012/07/15 08:22:57 wiz Exp $
#

PKGVER=		0.8.4
DISTNAME=	compiz-${PKGVER}
PKGREVISION=	20
CATEGORIES=	wm x11
MASTER_SITES=	http://releases.compiz.org/${PKGVER}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://compiz.org/
COMMENT=	Compositing window manager
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		intltool pkg-config msgfmt gmake
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

COMPIZ_GCONF_SCHEMAS+=		compiz-annotate.schemas
COMPIZ_GCONF_SCHEMAS+=		compiz-blur.schemas
COMPIZ_GCONF_SCHEMAS+=		compiz-clone.schemas
COMPIZ_GCONF_SCHEMAS+=		compiz-commands.schemas
COMPIZ_GCONF_SCHEMAS+=		compiz-core.schemas
COMPIZ_GCONF_SCHEMAS+=		compiz-cube.schemas
COMPIZ_GCONF_SCHEMAS+=		compiz-dbus.schemas
COMPIZ_GCONF_SCHEMAS+=		compiz-decoration.schemas
COMPIZ_GCONF_SCHEMAS+=		compiz-fade.schemas
COMPIZ_GCONF_SCHEMAS+=		compiz-fs.schemas
COMPIZ_GCONF_SCHEMAS+=		compiz-gconf.schemas
COMPIZ_GCONF_SCHEMAS+=		compiz-glib.schemas
COMPIZ_GCONF_SCHEMAS+=		compiz-gnomecompat.schemas
COMPIZ_GCONF_SCHEMAS+=		compiz-ini.schemas
COMPIZ_GCONF_SCHEMAS+=		compiz-inotify.schemas
COMPIZ_GCONF_SCHEMAS+=		compiz-kconfig.schemas
COMPIZ_GCONF_SCHEMAS+=		compiz-minimize.schemas
COMPIZ_GCONF_SCHEMAS+=		compiz-move.schemas
COMPIZ_GCONF_SCHEMAS+=		compiz-obs.schemas
COMPIZ_GCONF_SCHEMAS+=		compiz-place.schemas
COMPIZ_GCONF_SCHEMAS+=		compiz-png.schemas
COMPIZ_GCONF_SCHEMAS+=		compiz-regex.schemas
COMPIZ_GCONF_SCHEMAS+=		compiz-resize.schemas
COMPIZ_GCONF_SCHEMAS+=		compiz-rotate.schemas
COMPIZ_GCONF_SCHEMAS+=		compiz-scale.schemas
COMPIZ_GCONF_SCHEMAS+=		compiz-screenshot.schemas
COMPIZ_GCONF_SCHEMAS+=		compiz-svg.schemas
COMPIZ_GCONF_SCHEMAS+=		compiz-switcher.schemas
COMPIZ_GCONF_SCHEMAS+=		compiz-video.schemas
COMPIZ_GCONF_SCHEMAS+=		compiz-water.schemas
COMPIZ_GCONF_SCHEMAS+=		compiz-wobbly.schemas
COMPIZ_GCONF_SCHEMAS+=		compiz-zoom.schemas
GCONF_SCHEMAS+=		gwd.schemas
GCONF_SCHEMAS+=		${COMPIZ_GCONF_SCHEMAS}

PKGCONFIG_OVERRIDE+=	compiz.pc.in
PKGCONFIG_OVERRIDE+=	libdecoration/libdecoration.pc.in

CONFIGURE_ARGS+=	--disable-inotify

PKG_SUPPORTED_OPTIONS=	gnome kde
PKG_SUGGESTED_OPTIONS=	gnome
PKG_OPTIONS_VAR=	PKG_OPTIONS.compiz

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	metadata/decoration.xml.in
SUBST_SED.paths=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_STAGE.paths=	post-patch

post-install:
.for schema in ${COMPIZ_GCONF_SCHEMAS}
	${INSTALL_DATA} ${WRKSRC}/metadata/${schema} ${DESTDIR}${PREFIX}/share/gconf/schemas
.endfor

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		${PKG_SUPPORTED_OPTIONS}

# this is as much as needed for the basic window decorator
.include "../../graphics/cairo/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"

.if !empty(PKG_OPTIONS:Mgnome)
CONFIGURE_ARGS+=	--enable-librsvg
PLIST.gnome=		yes
.include "../../x11/gnome-control-center/buildlink3.mk"
.include "../../wm/metacity/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mkde)
PLIST.kde=		yes
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../sysutils/dbus-qt3/buildlink3.mk"
.endif

# While we don't use threads, we link against libpthread because
# some plugins do it.
.include "../../mk/pthread.buildlink3.mk"

.include "../../audio/libcanberra/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
