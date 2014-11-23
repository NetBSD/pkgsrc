# $NetBSD: Makefile,v 1.22 2014/11/23 13:46:07 prlw1 Exp $

DISTNAME=	gtksourceview-3.14.2
PKGNAME=	${DISTNAME:S/gtksourceview/gtksourceview3/}
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtksourceview/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://wiki.gnome.org/Projects/GtkSourceView
COMMENT=	Text widget that extends GTK3's GtkTextView widget
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake gsed intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	yes
#CONFIGURE_ARGS+=	--disable-deprecations
CONFIGURE_ARGS+=	--disable-maintainer-mode
CONFIGURE_ARGS+=	--disable-vala

PKGCONFIG_OVERRIDE+=	gtksourceview-3.0.pc.in

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.38
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk3+=	gtk3+>=3.13.7
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
