# $NetBSD: Makefile,v 1.34 2023/10/24 22:11:37 wiz Exp $

DISTNAME=	gtk-4.12.3
PKGNAME=	${DISTNAME:S/gtk/gtk4/}
PKGREVISION=	2
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
# ffmpeg backend is disabled by default
MESON_ARGS+=		-Dmedia-ffmpeg=enabled

PKGCONFIG_OVERRIDE+=	output/meson-private/gtk4.pc
PKGCONFIG_OVERRIDE+=	output/meson-private/gtk4-x11.pc
PKGCONFIG_OVERRIDE+=	output/meson-private/gtk4-unix-print.pc

PKGCONFIG_OVERRIDE_STAGE=	post-configure

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--export-dynamic

PLIST_VARS+=		dylib no-dylib
.if ${SHLIB_TYPE} == "dylib"
PLIST.dylib=		yes
SOEXT=			dylib
.else
PLIST.no-dylib=		yes
SOEXT=			so
.endif
PLIST_SUBST+=		SOEXT=${SOEXT}
PRINT_PLIST_AWK+=	{ gsub(/\.${SOEXT}/, ".$${SOEXT}") }

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
BUILDLINK_API_DEPENDS.pango+=	pango>=1.47.0
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../graphics/graphene/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libepoxy/buildlink3.mk"
# librsvg is required by a demo only.
#.include "../../graphics/librsvg/buildlink3.mk"
.include "../../multimedia/gst-plugins1-bad/buildlink3.mk"
# does not support ffmpeg6 yet
# https://gitlab.gnome.org/GNOME/gtk/-/issues/5581
.include "../../multimedia/ffmpeg5/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
