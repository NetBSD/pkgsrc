# $NetBSD: Makefile,v 1.70 2026/02/06 10:06:13 wiz Exp $

DISTNAME=	gtk-4.20.3
PKGNAME=	${DISTNAME:S/gtk/gtk4/}
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtk/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://www.gtk.org/
COMMENT=	Multi-platform toolkit for creating GUIs, version 4
LICENSE=	gnu-lgpl-v2.1

# TEST_DEPENDS, but meson fails if it's not found
TOOL_DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3
# TODO: add more python dependencies?
# gi-docgen| subprojects/gi-docgen/meson.build:10:0: Exception: python3 is missing modules: jinja2, markdown, markupsafe, pygments, toml, typogrify

# Gdk-4.0 dumps core with full RELRO
# http://gnats.netbsd.org/57792
RELRO_SUPPORTED=	partial

.include "options.mk"

USE_TOOLS+=	gdbus-codegen msgfmt msgmerge pkg-config xgettext
USE_LANGUAGES=	c c++
# meson.build only mentions c++11 to build harfbuzz as a subproject

MESON_REQD+=		1.5.0
MESON_ARGS+=		-Dintrospection=enabled
# needs gstreamer-gl
MESON_ARGS+=		-Dmedia-gstreamer=disabled
MESON_ARGS+=		-Dvulkan=disabled
MESON_ARGS+=		-Df16c=disabled

PKGCONFIG_OVERRIDE+=	output/meson-private/gtk4.pc
PKGCONFIG_OVERRIDE+=	output/meson-private/gtk4-x11.pc
PKGCONFIG_OVERRIDE+=	output/meson-private/gtk4-unix-print.pc

PKGCONFIG_OVERRIDE_STAGE=	post-configure

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--export-dynamic

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.80
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/meson/build.mk"
BUILDLINK_API_DEPENDS.pango+=	pango>=1.56
.include "../../devel/pango/buildlink3.mk"
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.18.2
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../graphics/graphene/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libepoxy/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../multimedia/gst-plugins1-bad/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
