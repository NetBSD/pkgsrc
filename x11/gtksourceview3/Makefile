# $NetBSD: Makefile,v 1.21 2014/10/26 07:55:49 adam Exp $

DISTNAME=	gtksourceview-3.10.3
PKGNAME=	${DISTNAME:S/gtksourceview/gtksourceview3/}
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtksourceview/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	http://projects.gnome.org/gtksourceview/
COMMENT=	Text widget that extends GTK3's GtkTextView widget
# LGPL, but some files used in tests are still GPL
LICENSE=	gnu-lgpl-v2 AND gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake gsed intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	yes
#CONFIGURE_ARGS+=	--disable-deprecations
CONFIGURE_ARGS+=	--disable-maintainer-mode

PKGCONFIG_OVERRIDE+=	gtksourceview-3.0.pc.in

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.37.3
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk3+=	gtk3+>=3.9.9
.include "../../x11/gtk3/buildlink3.mk"
.if !empty(PKG_BUILD_OPTIONS.gtk3:Mquartz)
.include "../../x11/gtk-mac-integration/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
