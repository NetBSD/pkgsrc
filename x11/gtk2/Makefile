# $NetBSD: Makefile,v 1.16 2002/11/29 17:25:22 wiz Exp $
#

DISTNAME=		gtk+-2.0.9
PKGNAME=		${DISTNAME:S/gtk/gtk2/}
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.gtk.org/pub/gtk/v2.0/ \
			ftp://ftp.cs.umn.edu/pub/gimp/gtk/v2.0/ \
			http://www.ameth.org/gimp/pub/gtk/v2.0/ \
			${MASTER_SITE_GNOME:=sources/gtk/2.0/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gtk.org/
COMMENT=		Gimp toolkit. Libraries for building X11 user interfaces

BUILD_USES_MSGFMT=	yes
USE_BUILDLINK2=		yes
USE_X11=		yes
USE_GMAKE=		yes

GNU_CONFIGURE=		 yes
CONFIGURE_ARGS+=	--with-xinput=xfree
MAKE_ENV+=		PKGLOCALEDIR="${PKGLOCALEDIR}"

USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/gdk-2.0.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gtk+-2.0.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gdk-pixbuf-2.0.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/contrib/gdk-pixbuf-xlib/gdk-pixbuf-xlib-2.0.pc.in

BUILD_DIRS=		${WRKSRC} ${WRKSRC}/demos/gtk-demo

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gtk-2.0/modules

.include "../../devel/atk/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/pango/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
