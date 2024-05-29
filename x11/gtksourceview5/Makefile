# $NetBSD: Makefile,v 1.6 2024/05/29 16:35:00 adam Exp $

DISTNAME=	gtksourceview-5.10.0
PKGNAME=	${DISTNAME:S/gtksourceview/gtksourceview5/}
PKGREVISION=	5
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtksourceview/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://wiki.gnome.org/Projects/GtkSourceView
COMMENT=	Text widget that extends GTK4's GtkTextView widget (v5)
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=		msgfmt pkg-config itstool

PKGCONFIG_OVERRIDE+=	gtksourceview.pc.in

MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/gtksourceview

PYTHON_FOR_BUILD_ONLY=	tool

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.48
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gobject-introspection+=	gobject-introspection>=1.42.0
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk4/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
