# $NetBSD: Makefile,v 1.4 2021/04/09 21:19:50 khorben Exp $

DISTNAME=	gtk-4.0.3
PKGNAME=	${DISTNAME:S/gtk/gtk4/}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtk/4.0/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://www.gtk.org/
COMMENT=	Multi-platform toolkit for creating GUIs, version 4
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=	gdbus-codegen-[0-9]*:../../devel/gdbus-codegen

# This package invokes python3 command.
PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "options.mk"

USE_TOOLS+=		pkg-config
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

MESON_ARGS+=		-Dsassc=disabled
MESON_ARGS+=		-Dgtk_doc=false

PKGCONFIG_OVERRIDE+=	gtk4-unix-print.pc.in
PKGCONFIG_OVERRIDE+=	gtk4.pc.in

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
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../graphics/graphene/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libepoxy/buildlink3.mk"
# librsvg is required by a demo only.
#.include "../../graphics/librsvg/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
# json-glib and librest07 are required to support Google Cloud Print.
# Google Cloud Print reached EOL (2020-12-31).
#.include "../../textproc/json-glib/buildlink3.mk"
#.include "../../www/librest07/buildlink3.mk"

.include "../../devel/meson/build.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
