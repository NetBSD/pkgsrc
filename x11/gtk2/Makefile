# $NetBSD: Makefile,v 1.302 2018/11/14 22:22:42 kleink Exp $

DISTNAME=	gtk+-2.24.32
PKGNAME=	${DISTNAME:S/gtk/gtk2/}
PKGREVISION=	7
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtk+/2.24/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gtk.org/
COMMENT=	GIMP Toolkit v2 - libraries for building X11 user interfaces
LICENSE=	gnu-lgpl-v2.1

# gtk-builder-convert uses minidom from xml.dom, which needs expat
DEPENDS+=		${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

CONFLICTS=		gtk2-engines<2.6.0
CONFLICTS+=		gail-[0-9]*

SUPERSEDES=		gail-[0-9]*

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		ggrep gmake msgfmt perl pkg-config
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
PTHREAD_AUTO_VARS=	yes

GNU_CONFIGURE=		yes
# bashism in "configure" (illegal variable substitution), patched
#CONFIG_SHELL=		bash
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/libdata
# Work around build problems, disable unstable PAPI, PR #41608:
CONFIGURE_ARGS+=	--disable-papi
# Not to unwanted pick up of db2html, PR#44908
CONFIGURE_ENV+=		ac_cv_prog_DB2HTML=false
MAKE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR}
TEST_TARGET=		check

PKGCONFIG_OVERRIDE=	gdk-2.0-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	gdk-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gtk+-2.0-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	gtk+-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gtk+-unix-print-2.0.pc.in
#PKGCONFIG_OVERRIDE+=	gdk-pixbuf-2.0-uninstalled.pc.in
#PKGCONFIG_OVERRIDE+=	gdk-pixbuf-2.0.pc.in
#PKGCONFIG_OVERRIDE+=	contrib/gdk-pixbuf-xlib/gdk-pixbuf-xlib-2.0.pc.in

INSTALLATION_DIRS+=	lib/gtk-2.0/immodules
INSTALLATION_DIRS+=	lib/gtk-2.0/modules
INSTALLATION_DIRS+=	lib/gtk-2.0/2.10.0/filesystems

REQD_DIRS+=		${PREFIX}/libdata/gtk-2.0

BUILD_DIRS=		. demos/gtk-demo

# fix for 'only weak aliases are supported on darwin' error
CONFIGURE_ARGS.Darwin+=	--disable-visibility

.include "../../mk/bsd.prefs.mk"

CPPFLAGS+=		-DPREFIX="\"${PREFIX}\""

#SUBST_CLASSES+=		pthread
#SUBST_STAGE.pthread=	pre-configure
#SUBST_MESSAGE.pthread=	Fixing pthread flags.
#SUBST_SED.pthread=	-e 's,__PTHREAD_FLAGS__,${BUILDLINK_LDFLAGS.pthread},g'
#SUBST_FILES.pthread=	gdk-pixbuf/Makefile.in

SUBST_CLASSES+=			iconcache
SUBST_STAGE.iconcache=		pre-configure
SUBST_MESSAGE.iconcache=	Renaming gtk-icon-cache-update.
SUBST_SED.iconcache=		-e 's,gtk-update-icon-cache,gtk2-update-icon-cache,g'
SUBST_FILES.iconcache=		gtk/Makefile.in

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # not yet ported as of 2.24.22
REPLACE_PYTHON=	gtk/gtk-builder-convert

# We remove the module databases during post-install since we create them
# anew in the +INSTALL script as part of the POST-INSTALL action.
#
post-install:
	${RM} -f ${DESTDIR}${GTK_IMMODULES_DB}

FILES_SUBST+=		GTK_UPDATE_ICON_CACHE="${PREFIX}/bin/gtk2-update-icon-cache"
FILES_SUBST+=		ICON_THEME_DIR="${LOCALBASE}/share/icons"
INSTALL_TEMPLATES+=	../../x11/gtk2/files/icon-cache.tmpl

_BUILDING_GTK2=	yes
.include "modules.mk"

.include "../../databases/shared-mime-info/buildlink3.mk"
BUILDLINK_API_DEPENDS.atk+=	atk>=1.30.0
.include "../../devel/atk/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.28.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
BUILDLINK_DEPMETHOD.gobject-introspection:=	build
BUILDLINK_API_DEPENDS.gobject-introspection+=	gobject-introspection>=0.9.3
.include "../../devel/gobject-introspection/buildlink3.mk"

.include "options.mk"

BUILDLINK_API_DEPENDS.pango+=	pango>=1.20.0
.include "../../devel/pango/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.6.0
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
#.include "../../mk/jpeg.buildlink3.mk"
#.include "../../graphics/png/buildlink3.mk"
#.include "../../graphics/tiff/buildlink3.mk"
.include "../../lang/python/application.mk"

.include "../../mk/bsd.pkg.mk"
