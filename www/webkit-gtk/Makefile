# $NetBSD: Makefile,v 1.152 2018/11/21 20:36:42 leot Exp $

DISTNAME=	webkitgtk-2.22.4
PKGNAME=	${DISTNAME:S/webkitgtk/webkit-gtk/}
CATEGORIES=	www
MASTER_SITES=	https://www.webkitgtk.org/releases/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.webkitgtk.org/
COMMENT=	GTK port of the WebKit browser engine
LICENSE=	2-clause-bsd AND gnu-lgpl-v2

# shm_open(3) and shm_unlink(3) appeared in NetBSD 7.0
NOT_FOR_PLATFORM=	NetBSD-[1-6].*-*

TOOL_DEPENDS+=	gettext-tools>=0.18:../../devel/gettext-tools

USE_CMAKE=	yes
USE_LANGUAGES=	c c++11
USE_TOOLS+=	automake bison gmake perl:build pkg-config msgfmt

# Enabling -gdwarf-2 hits GNU ar limits on file size.
CTF_SUPPORTED=	no

GCC_REQD+=	6

# Using ld.gold subverts Pkgsrc wrappers, and this package also crashes buggy
# versions of ld.gold.
CMAKE_ARGS+=	-DUSE_LD_GOLD=OFF

PKGCONFIG_OVERRIDE+=	Source/JavaScriptCore/javascriptcoregtk.pc.in
PKGCONFIG_OVERRIDE+=	Source/WebKit/gtk/webkit2gtk-web-extension.pc.in
PKGCONFIG_OVERRIDE+=	Source/WebKit/gtk/webkit2gtk.pc.in

CMAKE_ARGS+=		-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=		-DPORT=GTK
CMAKE_ARGS+=		-DENABLE_X11_TARGET=ON
CMAKE_ARGS+=		-DENABLE_MINIBROWSER=ON
CMAKE_ARGS+=		-DENABLE_GEOLOCATION=OFF
CMAKE_ARGS+=		-DUSE_GSTREAMER_GL=OFF
CMAKE_ARGS+=		-DUSE_LIBHYPHEN=OFF

REPLACE_PERL+=	Source/JavaScriptCore/create_hash_table
REPLACE_PERL+=	Source/WebCore/bindings/scripts/*.pl
REPLACE_PERL+=	Source/WebCore/bindings/scripts/*.pm
REPLACE_PERL+=	Source/WebCore/css/*.pl
REPLACE_PERL+=	Source/WebCore/dom/*.pl
REPLACE_PERL+=	Source/WebCore/make-hash-tools.pl

REPLACE_PYTHON+=	Source/JavaScriptCore/Scripts/*.py
REPLACE_PYTHON+=	Source/JavaScriptCore/Scripts/builtins/*.py
REPLACE_PYTHON+=	Source/JavaScriptCore/generate-bytecode-files
REPLACE_PYTHON+=	Source/JavaScriptCore/inspector/scripts/*.py
REPLACE_PYTHON+=	Source/JavaScriptCore/inspector/scripts/codegen/*.py
REPLACE_PYTHON+=	Source/JavaScriptCore/wasm/*.py
REPLACE_PYTHON+=	Source/JavaScriptCore/yarr/create_regex_tables
REPLACE_PYTHON+=	Source/JavaScriptCore/yarr/generateYarrCanonicalizeUnicode
REPLACE_PYTHON+=	Source/ThirdParty/gtest/*.py
REPLACE_PYTHON+=	Source/ThirdParty/gtest/scripts/*.py
REPLACE_PYTHON+=	Source/ThirdParty/gtest/test/*.py
REPLACE_PYTHON+=	Source/ThirdParty/gtest/xcode/Scripts/*.py
REPLACE_PYTHON+=	Source/WebCore/PAL/*.py
REPLACE_PYTHON+=	Source/WebCore/css/*.py
REPLACE_PYTHON+=	Source/WebCore/html/parser/create-html-entity-table
REPLACE_PYTHON+=	Source/WebCore/platform/network/create-http-header-name-table
REPLACE_PYTHON+=	Source/WebKit/Scripts/*.py
REPLACE_PYTHON+=	Tools/glib/*.py
REPLACE_PYTHON+=	Tools/gtk/*.py
REPLACE_PYTHON+=	Tools/gtk/generate-gtkdoc

SUBST_CLASSES+=		python
SUBST_FILES.python+=	Source/WebInspectorUI/Scripts/copy-user-interface-resources.pl
SUBST_SED.python+=	-e 's,\(.\)python.;,\1${PYTHONBIN}\1;,'
SUBST_STAGE.python=	pre-configure
SUBST_MESSAGE.python=	Fixing path to python binary.

.include "../../lang/ruby/rubyversion.mk"
TOOL_DEPENDS+=	${RUBY_BASE}>=${RUBY_VERSION}:${RUBY_SRCDIR}
CMAKE_ARGS+=	-DRUBY_EXECUTABLE=${RUBY}

PYTHON_FOR_BUILD_ONLY=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # not yet ported as of 2.22.2
.include "../../lang/python/application.mk"
CMAKE_ARGS+=	-DPYTHON_EXECUTABLE=${PYTHONBIN}

CXXFLAGS.SunOS+=	-fpermissive

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CXXFLAGS+=	-Wno-c++11-narrowing
.endif

# This does not disable optimisations, merely avoids #error if there are none.
CFLAGS+=	-DRELEASE_WITHOUT_OPTIMIZATIONS

NOT_PAX_MPROTECT_SAFE+=	libexec/webkit2gtk-4.0/WebKitWebProcess
NOT_PAX_MPROTECT_SAFE+=	libexec/webkit2gtk-4.0/jsc

.include "options.mk"

BUILDLINK_API_DEPENDS.glib2+= glib2>=2.32.1
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
# A correct Webkit build requires flex 2.5.33
.include "../../devel/flex/buildlink3.mk"
.include "../../devel/gperf/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../fonts/woff2/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
BUILDLINK_API_DEPENDS.png+= png>=1.5.1beta08
.include "../../graphics/png/buildlink3.mk"
BUILDLINK_API_DEPENDS.gstreamer1+=	gstreamer1>=1.0.3
.include "../../multimedia/gstreamer1/buildlink3.mk"
BUILDLINK_API_DEPENDS.gst-plugins1-base+=	gst-plugins1-base>=1.0.3
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
BUILDLINK_API_DEPENDS.libsoup+= libsoup>=2.42.2nb3
.include "../../net/libsoup/buildlink3.mk"
.include "../../security/libsecret/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.24.17nb3
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
