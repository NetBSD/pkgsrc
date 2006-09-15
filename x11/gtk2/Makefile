# $NetBSD: Makefile,v 1.127 2006/09/15 15:06:07 jmmv Exp $

DISTNAME=		gtk+-2.10.3
PKGNAME=		${DISTNAME:S/gtk/gtk2/}
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.gtk.org/pub/gtk/v2.10/ \
			ftp://ftp.cs.umn.edu/pub/gimp/gtk/v2.10/ \
			${MASTER_SITE_GNOME:=sources/gtk+/2.10/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.gtk.org/
COMMENT=		GIMP Toolkit v2 - libraries for building X11 user interfaces

CONFLICTS=		gtk2-engines<2.6.0

BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.2.0
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.12.0
BUILDLINK_API_DEPENDS.pango+=	pango>=1.13.0
BUILDLINK_API_DEPENDS.Xft2+=	Xft2>=2.1.2nb2

USE_DIRS+=		xdg-1.1
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake msgfmt perl pkg-config
USE_LIBTOOL=		yes
PTHREAD_AUTO_VARS=	yes

GNU_CONFIGURE=		 yes
CONFIGURE_ARGS+=	--with-xinput=xfree
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/libdata
CONFIGURE_ARGS+=	--enable-gtk-doc=no
CONFIGURE_ENV+=		ac_cv_header_X11_extensions_Xinerama_h=no
CONFIGURE_ENV+=		ac_cv_lib_Xinerama_XineramaQueryExtension=no
MAKE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR:Q}
TEST_TARGET=		check

PKGCONFIG_OVERRIDE=	gdk-2.0-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	gdk-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gtk+-2.0-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	gtk+-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gtk+-unix-print-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gdk-pixbuf-2.0-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	gdk-pixbuf-2.0.pc.in
PKGCONFIG_OVERRIDE+=	contrib/gdk-pixbuf-xlib/gdk-pixbuf-xlib-2.0.pc.in

REQD_DIRS+=		${PREFIX}/libdata/gtk-2.0

BUILD_DIRS=		${WRKSRC} ${WRKSRC}/demos/gtk-demo

.include "../../mk/bsd.prefs.mk"

CPPFLAGS+=		-DPREFIX="\"${PREFIX}\""

PRINT_PLIST_AWK+=	/^@dirrm share\/themes\/Default$$/ \
				{ print "@unexec $${RMDIR} %D/" $$2 \
				  " 2>/dev/null || $${TRUE}"; next; }

SUBST_CLASSES+=		pthread
SUBST_STAGE.pthread=	pre-configure
SUBST_MESSAGE.pthread=	Fixing pthread flags.
SUBST_SED.pthread=	-e 's,__PTHREAD_FLAGS__,${BUILDLINK_LDFLAGS.pthread},g'
SUBST_FILES.pthread=	gdk-pixbuf/Makefile.in

.include "options.mk"

.include "../../mk/compiler.mk"

.if ${OPSYS} == "IRIX" && !empty(CC_VERSION:Mgcc*)
USE_TOOLS+=		gawk
.endif

# We remove the module databases during post-install since we create them
# anew in the +INSTALL script as part of the POST-INSTALL action.
#
post-install:
	${RM} -f ${GTK_IMMODULES_DB}
	${RM} -f ${GDK_PIXBUF_LOADERS_DB}
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gtk-2.0/immodules
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gtk-2.0/modules
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gtk-2.0/2.10.0/filesystems

_BUILDING_GTK2=	yes
.include "modules.mk"

.include "../../devel/atk/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/xcursor/buildlink3.mk"
.include "../../x11/Xfixes/buildlink3.mk"
.include "../../x11/Xrandr/buildlink3.mk"
.include "../../x11/Xrender/buildlink3.mk"

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
