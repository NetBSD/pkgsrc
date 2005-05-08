# $NetBSD: Makefile,v 1.82 2005/05/08 09:07:08 jmmv Exp $
#

DISTNAME=		gtk+-2.6.7
PKGNAME=		${DISTNAME:S/gtk/gtk2/}
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.gtk.org/pub/gtk/v2.6/ \
			ftp://ftp.cs.umn.edu/pub/gimp/gtk/v2.6/ \
			${MASTER_SITE_GNOME:=sources/gtk+/2.6/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@NetBSD.org
HOMEPAGE=		http://www.gtk.org/
COMMENT=		GIMP Toolkit v2 - libraries for building X11 user interfaces

CONFLICTS=		gtk2-engines<2.6.0

BUILD_USES_MSGFMT=	yes

BUILDLINK_DEPENDS.glib2+=	glib2>=2.6.2
BUILDLINK_DEPENDS.pango+=	pango>=1.8.0
BUILDLINK_DEPENDS.Xft2+=	Xft2>=2.1.2nb2

USE_DIRS+=		xdg-1.1
USE_PKGINSTALL=		yes
USE_PKGLOCALEDIR=	yes
USE_X11=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
PTHREAD_AUTO_VARS=	yes

GNU_CONFIGURE=		 yes
CONFIGURE_ARGS+=	--with-xinput=xfree
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/libdata
CONFIGURE_ARGS+=	--enable-gtk-doc=no
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc
CONFIGURE_ENV+=		ac_cv_header_X11_extensions_Xinerama_h=no
CONFIGURE_ENV+=		ac_cv_lib_Xinerama_XineramaQueryExtension=no
MAKE_ENV+=		PKGLOCALEDIR="${PKGLOCALEDIR}"
TEST_TARGET=		check

PKGCONFIG_OVERRIDE=	gdk-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gtk+-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gdk-pixbuf-2.0.pc.in
PKGCONFIG_OVERRIDE+=	contrib/gdk-pixbuf-xlib/gdk-pixbuf-xlib-2.0.pc.in

MAKE_DIRS+=		${PREFIX}/libdata/gtk-2.0

BUILD_DIRS=		${WRKSRC} ${WRKSRC}/demos/gtk-demo

CPPFLAGS+=		-DPREFIX="\"${PREFIX}\""

PRINT_PLIST_AWK+=	/^@dirrm share\/themes\/Default$$/ \
				{ print "@unexec $${RMDIR} %D/" $$2 \
				  " 2>/dev/null || $${TRUE}"; next; }

SUBST_CLASSES=		pthread
SUBST_STAGE.pthread=	pre-configure
SUBST_MESSAGE.pthread=	"Fixing pthread flags."
SUBST_SED.pthread=	-e 's,__PTHREAD_FLAGS__,${BUILDLINK_LDFLAGS.pthread},g'
SUBST_FILES.pthread=	gdk-pixbuf/Makefile.in

.include "../../mk/compiler.mk"

# work around /**/ in a macro definition in X11/Xlibint.h (GetEmptyReq)
# being expanded to a space, causing breakage in gdk/x11/gdkasync.c.
#
# turning on strict ISO C compliance uses a different macro definition
# which uses ## instead and does what it should.
.if !empty(CC_VERSION:MSun)
CPPFLAGS+=		-Xc
.elif ${OPSYS} == "IRIX" && !empty(CC_VERSION:Mgcc*)
USE_GNU_TOOLS+=		awk
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gtk-2.0/modules
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gtk-2.0/2.4.0/filesystems

_BUILDING_GTK2=	yes
.include "modules.mk"

.include "../../devel/atk/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/xcursor/buildlink3.mk"
.include "../../x11/Xfixes/buildlink3.mk"
.include "../../x11/Xrandr/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
