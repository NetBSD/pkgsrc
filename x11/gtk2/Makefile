# $NetBSD: Makefile,v 1.41 2004/02/10 02:04:54 xtraeme Exp $
#

DISTNAME=		gtk+-2.2.4
PKGNAME=		${DISTNAME:S/gtk/gtk2/}
PKGREVISION=		3
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.gtk.org/pub/gtk/v2.2/ \
			ftp://ftp.cs.umn.edu/pub/gimp/gtk/v2.2/ \
			${MASTER_SITE_GNOME:=sources/gtk+/2.2/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://www.gtk.org/
COMMENT=		The GIMP Toolkit - libraries for building X11 user interfaces

BUILD_USES_MSGFMT=	yes
USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes
USE_PKGLOCALEDIR=	yes
USE_X11=		yes
USE_GNU_TOOLS+=		make

GNU_CONFIGURE=		 yes
CONFIGURE_ARGS+=	--with-xinput=xfree
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/libdata
CONFIGURE_ARGS+=	--enable-gtk-doc=no
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html
CONFIGURE_ENV+=		ac_cv_header_X11_extensions_Xinerama_h=no
CONFIGURE_ENV+=		ac_cv_lib_Xinerama_XineramaQueryExtension=no
MAKE_ENV+=		PKGLOCALEDIR="${PKGLOCALEDIR}"
TEST_TARGET=		check

USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/gdk-2.0.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gtk+-2.0.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gdk-pixbuf-2.0.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/contrib/gdk-pixbuf-xlib/gdk-pixbuf-xlib-2.0.pc.in

BUILD_DIRS=		${WRKSRC} ${WRKSRC}/demos/gtk-demo

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gtk-2.0/engines
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gtk-2.0/modules

.include "../../devel/atk/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
