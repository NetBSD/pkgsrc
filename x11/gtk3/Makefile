# $NetBSD: Makefile,v 1.146 2020/04/12 20:41:57 wiz Exp $

DISTNAME=	gtk+-3.24.18
PKGNAME=	${DISTNAME:S/gtk/gtk3/}
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtk+/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gtk.org/
COMMENT=	GIMP Toolkit v3 - libraries for building X11 user interfaces
LICENSE=	gnu-lgpl-v2.1

USE_PKGLOCALEDIR=		yes
USE_TOOLS+=			ggrep gmake perl pkg-config bash xgettext msgmerge
USE_LANGUAGES=			c c++
USE_LIBTOOL=			yes
PTHREAD_AUTO_VARS=		yes
TOOL_DEPENDS+=			gdbus-codegen-[0-9]*:../../devel/gdbus-codegen
TOOL_DEPENDS+=			gettext-tools>=0.19.4nb1:../../devel/gettext-tools
# There is no logic in gettext.mk to detect the native version of xgettext,
# and we do need it to be compiled with Glade support.
_TOOLS_USE_PKGSRC.xgettext=	yes

GNU_CONFIGURE=		yes
# XXX there is a subtle bashism in "configure" or a bug in NetBSD's sh
CONFIG_SHELL=		${TOOLS_PATH.bash}
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/libdata
# Work around build problems, disable unstable PAPI, PR #41608:
CONFIGURE_ARGS+=	--disable-papi
# Avoid regeneration of Makefile.in after configure.ac patch
CONFIGURE_ARGS+=	--disable-maintainer-mode
MAKE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR}
TEST_TARGET=		check

PKGCONFIG_OVERRIDE+=	gdk-3.0.pc.in
PKGCONFIG_OVERRIDE+=	gtk+-3.0.pc.in
PKGCONFIG_OVERRIDE+=	gtk+-unix-print-3.0.pc.in
PKGCONFIG_OVERRIDE+=	gail-3.0.pc.in

INSTALLATION_DIRS+=	lib/gtk-3.0/immodules
INSTALLATION_DIRS+=	lib/gtk-3.0/modules
INSTALLATION_DIRS+=	lib/gtk-3.0/3.0.0/filesystems

BUILD_DIRS=		. demos/gtk-demo

.include "../../mk/bsd.prefs.mk"

# isnan and isinf are part of libc, not libm on DragonFly
# conf tests fail detection due to conflicting definitions, just skip them
CONFIGURE_ENV.DragonFly+=	ac_cv_func_isinf=yes
CONFIGURE_ENV.DragonFly+=	ac_cv_func_isnan=yes

CFLAGS.SunOS+=		-std=gnu99

CPPFLAGS+=		-DPREFIX="\"${PREFIX}\""

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
BUILDLINK_DEPMETHOD.gobject-introspection:=	build
BUILDLINK_API_DEPENDS.gobject-introspection+=	gobject-introspection>=1.39.0
.include "../../devel/gobject-introspection/buildlink3.mk"

.include "options.mk"

.include "../../devel/glib2/schemas.mk"

BUILDLINK_API_DEPENDS.pango+=	pango>=1.41
.include "../../devel/pango/buildlink3.mk"
BUILDLINK_API_DEPENDS.fontconfig+=	fontconfig>=2.11.91
.include "../../fonts/fontconfig/buildlink3.mk"
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.14.0
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libepoxy+=	libepoxy>=1.4
.include "../../graphics/libepoxy/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../mk/bsd.pkg.mk"
