# $NetBSD: Makefile,v 1.139 2022/01/10 01:46:46 ryoon Exp $
#

PKGVER=		0.8.8
DISTNAME=	compiz-${PKGVER}
PKGREVISION=	69
CATEGORIES=	wm x11
MASTER_SITES=	http://releases.compiz.org/${PKGVER}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://compiz.org/
COMMENT=	Compositing window manager
LICENSE=	mit

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake intltool msgfmt msgmerge pkg-config xgettext
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
CONFIGURE_ARGS+=	--disable-gnome --disable-gnome-keybindings

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

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	metadata/decoration.xml.in
SUBST_VARS.paths=	PREFIX
SUBST_STAGE.paths=	pre-configure

.include "options.mk"

BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:M*}

post-install:
.for schema in ${COMPIZ_GCONF_SCHEMAS}
	${INSTALL_DATA} ${WRKSRC}/metadata/${schema} ${DESTDIR}${PREFIX}/share/gconf/schemas
.endfor

# this is as much as needed for the basic window decorator
BUILDLINK_DEPMETHOD.pango=	build
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"

# While we don't use threads, we link against libpthread because
# some plugins do it. Same for dlopen.
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"

.include "../../x11/libxshmfence/buildlink3.mk"
.include "../../audio/libcanberra/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
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
BUILDLINK_API_DEPENDS.libXrender+=	libXrender>=0.9.3
.include "../../x11/libXrender/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
