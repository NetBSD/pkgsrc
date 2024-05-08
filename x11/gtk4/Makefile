# $NetBSD: Makefile,v 1.45 2024/05/08 18:44:11 adam Exp $

DISTNAME=	gtk-4.14.4
PKGNAME=	${DISTNAME:S/gtk/gtk4/}
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

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "options.mk"

USE_TOOLS+=	gdbus-codegen msgfmt msgmerge pkg-config xgettext
USE_LANGUAGES=	c c++

MESON_REQD+=		0.60.0
MESON_ARGS+=		-Dintrospection=enabled
# needs gstreamer-gl
MESON_ARGS+=		-Dmedia-gstreamer=disabled
MESON_ARGS+=		-Dvulkan=disabled

PKGCONFIG_OVERRIDE+=	output/meson-private/gtk4.pc
PKGCONFIG_OVERRIDE+=	output/meson-private/gtk4-x11.pc
PKGCONFIG_OVERRIDE+=	output/meson-private/gtk4-unix-print.pc

PKGCONFIG_OVERRIDE_STAGE=	post-configure

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--export-dynamic

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/meson/build.mk"
BUILDLINK_API_DEPENDS.pango+=	pango>=1.47.0
.include "../../devel/pango/buildlink3.mk"
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.18
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../graphics/graphene/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libepoxy/buildlink3.mk"
# librsvg is required by a demo only.
#.include "../../graphics/librsvg/buildlink3.mk"
.include "../../multimedia/gst-plugins1-bad/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
