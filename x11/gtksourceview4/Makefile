# $NetBSD: Makefile,v 1.15 2020/06/02 08:23:02 adam Exp $

DISTNAME=	gtksourceview-4.6.0
PKGNAME=	${DISTNAME:S/gtksourceview/gtksourceview4/}
PKGREVISION=	2
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtksourceview/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://wiki.gnome.org/Projects/GtkSourceView
COMMENT=	Text widget that extends GTK3's GtkTextView widget (v4)
LICENSE=	gnu-lgpl-v2.1

BUILD_DEPENDS+=		itstool-[0-9]*:../../textproc/itstool

USE_TOOLS+=		intltool msgfmt pkg-config

# avoid vala dependency
MESON_ARGS+=		-Dvapi=false

PKGCONFIG_OVERRIDE+=	gtksourceview.pc.in

MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/gtksourceview

.include "options.mk"

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.48
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk3+=	gtk3+>=3.22
.include "../../x11/gtk3/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
