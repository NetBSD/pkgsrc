# $NetBSD: Makefile,v 1.149 2007/11/29 22:10:17 drochner Exp $

DISTNAME=		gtk+-2.12.2
PKGNAME=		${DISTNAME:S/gtk/gtk2/}
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.gtk.org/pub/gtk/2.12/ \
			ftp://ftp.cs.umn.edu/pub/gimp/pub/gtk/2.12/ \
			${MASTER_SITE_GNOME:=sources/gtk+/2.12/}
EXTRACT_SUFX=		.tar.bz2

# temporary hack for 2.12.2: use correctly built html doc
FIXEDDOC=	gtk+-2.12.2-gtkdoc-html.tar.bz2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${FIXEDDOC}
SITES.${FIXEDDOC}=	${MASTER_SITE_LOCAL}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gtk.org/
COMMENT=		GIMP Toolkit v2 - libraries for building X11 user interfaces

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=		gtk2-engines<2.6.0

BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.2.0
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.13.5
BUILDLINK_API_DEPENDS.pango+=	pango>=1.17.3

USE_DIRS+=		xdg-1.1
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake msgfmt perl pkg-config
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
PTHREAD_AUTO_VARS=	yes

GNU_CONFIGURE=		 yes
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/libdata
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

# XXX temporary hack, remove on update
# The gtk-doc (html) docs are not properly packaged in 2.12.2.
# Will hopefully fixed in the next gtk release.
USE_TOOLS+=	bzcat tar
post-configure:
	${BZCAT} <${DISTDIR}/${DIST_SUBDIR}/${FIXEDDOC} | \
		(cd ${WRKDIR} && ${TAR} xf -)
	(cd ${WRKSRC}/docs/reference/gtk && ${GMAKE} just-copy-images)

.include "options.mk"

.include "../../mk/compiler.mk"

.if ${OPSYS} == "IRIX" && !empty(CC_VERSION:Mgcc*)
USE_TOOLS+=		gawk
.endif

# We remove the module databases during post-install since we create them
# anew in the +INSTALL script as part of the POST-INSTALL action.
#
post-install:
	${RM} -f ${DESTDIR}${GTK_IMMODULES_DB}
	${RM} -f ${DESTDIR}${GDK_PIXBUF_LOADERS_DB}
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/gtk-2.0/immodules
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/gtk-2.0/modules
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/gtk-2.0/2.10.0/filesystems

EVAL_PREFIX+=		PREFIX.hicolor=hicolor-icon-theme
FILES_SUBST+=		GTK_UPDATE_ICON_CACHE="${PREFIX}/bin/gtk-update-icon-cache"
FILES_SUBST+=		ICON_THEME_DIR="${PREFIX.hicolor}/share/icons/hicolor"
INSTALL_TEMPLATES+=	../../x11/gtk2/files/icon-cache.tmpl
PRINT_PLIST_AWK+=	/^share\/icons\/hicolor\/icon-theme.cache$$/ { next; }

_BUILDING_GTK2=	yes
.include "modules.mk"

.include "../../devel/atk/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
