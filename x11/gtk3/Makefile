# $NetBSD: Makefile,v 1.199 2024/05/16 06:15:45 wiz Exp $

DISTNAME=	gtk+-3.24.41
PKGNAME=	${DISTNAME:S/gtk/gtk3/}
PKGREVISION=	3
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtk+/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gtk.org/
COMMENT=	GIMP Toolkit v3 - libraries for building X11 user interfaces
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=	gettext-tools>=0.19.4nb1:../../devel/gettext-tools
TOOL_DEPENDS+=	gtk-doc>=1.32:../../textproc/gtk-doc

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		bash gdbus-codegen ggrep msgmerge perl pkg-config xgettext
PTHREAD_AUTO_VARS=	yes

# "error: 'for' loop initial declarations are only allowed in C99 mode"
# tests need M_PI, ISO C unacceptable on illumos
FORCE_C_STD=	gnu99

MESON_ARGS+=	-Dgtk_doc=true
MESON_ARGS+=	-Dman=true
MESON_ARGS+=	--localedir=${PREFIX}/${PKGLOCALEDIR}/locale
MESON_ARGS+=	--sysconfdir=${PREFIX}/libdata

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--export-dynamic

MAKE_ENV.Darwin+=	DYLD_LIBRARY_PATH=${WRKSRC}/output/gdk:${WRKSRC}/output/gtk

# There is no logic in gettext.mk to detect the native version of xgettext,
# and we do need it to be compiled with Glade support.
_TOOLS_USE_PKGSRC.xgettext=	yes

TEST_TARGET=		check

PKGCONFIG_OVERRIDE+=	gdk-3.0.pc.in
PKGCONFIG_OVERRIDE+=	gtk+-3.0.pc.in
PKGCONFIG_OVERRIDE+=	gtk+-unix-print-3.0.pc.in
PKGCONFIG_OVERRIDE+=	gail-3.0.pc.in

INSTALLATION_DIRS+=	lib/gtk-3.0/immodules
INSTALLATION_DIRS+=	lib/gtk-3.0/modules
INSTALLATION_DIRS+=	lib/gtk-3.0/3.0.0/filesystems

.include "../../mk/bsd.prefs.mk"

# We remove the module databases during post-install since we create them
# anew in the +INSTALL script as part of the POST-INSTALL action.
#
post-install:
	${RM} -f ${DESTDIR}${GTK3_IMMODULES_DB}

FILES_SUBST+=		GTK_UPDATE_ICON_CACHE="${PREFIX}/bin/gtk-update-icon-cache"
FILES_SUBST+=		ICON_THEME_DIR="${PREFIX}/share/icons"
INSTALL_TEMPLATES+=	../../x11/gtk2/files/icon-cache.tmpl

_BUILDING_GTK3=	yes
.include "modules.mk"

.include "../../converters/fribidi/buildlink3.mk"
.include "../../databases/shared-mime-info/buildlink3.mk"
BUILDLINK_API_DEPENDS.atk+=	atk>=2.15.1
.include "../../devel/atk/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.57.2
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gdk-pixbuf2+=	gdk-pixbuf2>=2.30.0
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gobject-introspection+=	gobject-introspection>=1.39.0
.include "../../devel/gobject-introspection/buildlink3.mk"

.include "options.mk"

.include "../../devel/glib2/schemas.mk"
.include "../../devel/meson/build.mk"
BUILDLINK_API_DEPENDS.pango+=	pango>=1.41
.include "../../devel/pango/buildlink3.mk"
BUILDLINK_API_DEPENDS.fontconfig+=	fontconfig>=2.11.91
.include "../../fonts/fontconfig/buildlink3.mk"
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.18
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libepoxy+=	libepoxy>=1.4
.include "../../graphics/libepoxy/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
