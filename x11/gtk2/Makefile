# $NetBSD: Makefile,v 1.63 2004/10/04 11:11:23 grant Exp $
#

DISTNAME=		gtk+-2.4.10
PKGNAME=		${DISTNAME:S/gtk/gtk2/}
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.gtk.org/pub/gtk/v2.4/ \
			ftp://ftp.cs.umn.edu/pub/gimp/gtk/v2.4/ \
			${MASTER_SITE_GNOME:=sources/gtk+/2.4/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@NetBSD.org
HOMEPAGE=		http://www.gtk.org/
COMMENT=		GIMP Toolkit v2 - libraries for building X11 user interfaces

BUILD_USES_MSGFMT=	yes
BUILDLINK_DEPENDS.Xft2+=	Xft2>=2.1.2nb2

USE_BUILDLINK3=		yes
USE_DIRS+=		xdg-1.1
USE_PKGINSTALL=		yes
USE_PKGLOCALEDIR=	yes
USE_X11=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes

GNU_CONFIGURE=		 yes
CONFIGURE_ARGS+=	--with-xinput=xfree
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/libdata
CONFIGURE_ARGS+=	--enable-gtk-doc=no
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc
CONFIGURE_ENV+=		ac_cv_header_X11_extensions_Xinerama_h=no
CONFIGURE_ENV+=		ac_cv_lib_Xinerama_XineramaQueryExtension=no
MAKE_ENV+=		PKGLOCALEDIR="${PKGLOCALEDIR}"
MAKE_ENV+=		PTHREAD_LDFLAGS="${PTHREAD_LDFLAGS}"
TEST_TARGET=		check

PKGCONFIG_OVERRIDE=	gdk-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gtk+-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gdk-pixbuf-2.0.pc.in
PKGCONFIG_OVERRIDE+=	contrib/gdk-pixbuf-xlib/gdk-pixbuf-xlib-2.0.pc.in

MAKE_DIRS+=		${PREFIX}/libdata/gtk-2.0

BUILD_DIRS=		${WRKSRC} ${WRKSRC}/demos/gtk-demo

PRINT_PLIST_AWK+=	/^@dirrm share\/themes\/Default$$/ \
				{ print "@unexec $${RMDIR} %D/" $$2 \
				  " 2>/dev/null || $${TRUE}"; next; }

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
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gtk-2.0/engines
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gtk-2.0/modules
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gtk-2.0/2.4.0/engines
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
.include "../../x11/Xrandr/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
