# $NetBSD: Makefile,v 1.139.2.1 2018/08/24 20:07:26 bsiegert Exp $

DISTNAME=	webkitgtk-2.20.4
PKGNAME=	${DISTNAME:S/webkitgtk/webkit-gtk/}
CATEGORIES=	www
MASTER_SITES=	https://www.webkitgtk.org/releases/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.webkitgtk.org/
COMMENT=	GTK port of the WebKit browser engine
LICENSE=	2-clause-bsd AND gnu-lgpl-v2

# shm_open(3) and shm_unlink(3) appeared in NetBSD 7.0
NOT_FOR_PLATFORM=	NetBSD-[1-6]*-*

BUILD_DEPENDS+=	gettext-tools>=0.18:../../devel/gettext-tools

USE_CMAKE=	yes
USE_LANGUAGES=	c c++11
#USE_LIBTOOL=	yes
USE_TOOLS+=	automake bison gmake perl:build pkg-config msgfmt

GCC_REQD+=	5.0

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
#CMAKE_ARGS+=		-DUSE_SYSTEM_MALLOC=ON # XXX: needs adjustements for sysinfo() stuffs in Source/WTF/wtf/RAMSize.cpp

REPLACE_PERL+=	Source/JavaScriptCore/create_hash_table
REPLACE_PERL+=	Source/WebCore/bindings/scripts/*.pl
REPLACE_PERL+=	Source/WebCore/bindings/scripts/InFilesCompiler.pm
REPLACE_PERL+=	Source/WebCore/bindings/scripts/InFilesParser.pm
REPLACE_PERL+=	Source/WebCore/css/*.pl
REPLACE_PERL+=	Source/WebCore/dom/*.pl
REPLACE_PERL+=	Source/WebCore/make-hash-tools.pl

REPLACE_PYTHON+=	Source/JavaScriptCore/Scripts/UpdateContents.py
REPLACE_PYTHON+=	Source/JavaScriptCore/Scripts/builtins/builtins_generate_combined_header.py
REPLACE_PYTHON+=	Source/JavaScriptCore/Scripts/builtins/builtins_generate_combined_implementation.py
REPLACE_PYTHON+=	Source/JavaScriptCore/Scripts/builtins/builtins_generate_internals_wrapper_header.py
REPLACE_PYTHON+=	Source/JavaScriptCore/Scripts/builtins/builtins_generate_internals_wrapper_implementation.py
REPLACE_PYTHON+=	Source/JavaScriptCore/Scripts/builtins/builtins_generate_separate_header.py
REPLACE_PYTHON+=	Source/JavaScriptCore/Scripts/builtins/builtins_generate_separate_implementation.py
REPLACE_PYTHON+=	Source/JavaScriptCore/Scripts/builtins/builtins_generate_wrapper_header.py
REPLACE_PYTHON+=	Source/JavaScriptCore/Scripts/builtins/builtins_generate_wrapper_implementation.py
REPLACE_PYTHON+=	Source/JavaScriptCore/Scripts/builtins/builtins_generator.py
REPLACE_PYTHON+=	Source/JavaScriptCore/Scripts/builtins/builtins_model.py
REPLACE_PYTHON+=	Source/JavaScriptCore/Scripts/builtins/builtins_templates.py
REPLACE_PYTHON+=	Source/JavaScriptCore/Scripts/cssmin.py
REPLACE_PYTHON+=	Source/JavaScriptCore/Scripts/generate-combined-inspector-json.py
REPLACE_PYTHON+=	Source/JavaScriptCore/Scripts/generate-js-builtins.py
REPLACE_PYTHON+=	Source/JavaScriptCore/Scripts/generateYarrUnicodePropertyTables.py
REPLACE_PYTHON+=	Source/JavaScriptCore/Scripts/hasher.py
REPLACE_PYTHON+=	Source/JavaScriptCore/Scripts/inline-and-minify-stylesheets-and-scripts.py
REPLACE_PYTHON+=	Source/JavaScriptCore/Scripts/lazywriter.py
REPLACE_PYTHON+=	Source/JavaScriptCore/Scripts/make-js-file-arrays.py
REPLACE_PYTHON+=	Source/JavaScriptCore/generate-bytecode-files
REPLACE_PYTHON+=	Source/JavaScriptCore/inspector/scripts/codegen/cpp_generator.py
REPLACE_PYTHON+=	Source/JavaScriptCore/inspector/scripts/codegen/cpp_generator_templates.py
REPLACE_PYTHON+=	Source/JavaScriptCore/inspector/scripts/codegen/generate_cpp_alternate_backend_dispatcher_header.py
REPLACE_PYTHON+=	Source/JavaScriptCore/inspector/scripts/codegen/generate_cpp_backend_dispatcher_header.py
REPLACE_PYTHON+=	Source/JavaScriptCore/inspector/scripts/codegen/generate_cpp_backend_dispatcher_implementation.py
REPLACE_PYTHON+=	Source/JavaScriptCore/inspector/scripts/codegen/generate_cpp_frontend_dispatcher_header.py
REPLACE_PYTHON+=	Source/JavaScriptCore/inspector/scripts/codegen/generate_cpp_frontend_dispatcher_implementation.py
REPLACE_PYTHON+=	Source/JavaScriptCore/inspector/scripts/codegen/generate_cpp_protocol_types_header.py
REPLACE_PYTHON+=	Source/JavaScriptCore/inspector/scripts/codegen/generate_cpp_protocol_types_implementation.py
REPLACE_PYTHON+=	Source/JavaScriptCore/inspector/scripts/codegen/generate_js_backend_commands.py
REPLACE_PYTHON+=	Source/JavaScriptCore/inspector/scripts/codegen/generate_objc_backend_dispatcher_header.py
REPLACE_PYTHON+=	Source/JavaScriptCore/inspector/scripts/codegen/generate_objc_backend_dispatcher_implementation.py
REPLACE_PYTHON+=	Source/JavaScriptCore/inspector/scripts/codegen/generate_objc_configuration_header.py
REPLACE_PYTHON+=	Source/JavaScriptCore/inspector/scripts/codegen/generate_objc_configuration_implementation.py
REPLACE_PYTHON+=	Source/JavaScriptCore/inspector/scripts/codegen/generate_objc_frontend_dispatcher_implementation.py
REPLACE_PYTHON+=	Source/JavaScriptCore/inspector/scripts/codegen/generate_objc_header.py
REPLACE_PYTHON+=	Source/JavaScriptCore/inspector/scripts/codegen/generate_objc_internal_header.py
REPLACE_PYTHON+=	Source/JavaScriptCore/inspector/scripts/codegen/generate_objc_protocol_type_conversions_header.py
REPLACE_PYTHON+=	Source/JavaScriptCore/inspector/scripts/codegen/generate_objc_protocol_type_conversions_implementation.py
REPLACE_PYTHON+=	Source/JavaScriptCore/inspector/scripts/codegen/generate_objc_protocol_types_implementation.py
REPLACE_PYTHON+=	Source/JavaScriptCore/inspector/scripts/codegen/generator.py
REPLACE_PYTHON+=	Source/JavaScriptCore/inspector/scripts/codegen/generator_templates.py
REPLACE_PYTHON+=	Source/JavaScriptCore/inspector/scripts/codegen/models.py
REPLACE_PYTHON+=	Source/JavaScriptCore/inspector/scripts/codegen/objc_generator.py
REPLACE_PYTHON+=	Source/JavaScriptCore/inspector/scripts/codegen/objc_generator_templates.py
REPLACE_PYTHON+=	Source/JavaScriptCore/inspector/scripts/generate-inspector-protocol-bindings.py
REPLACE_PYTHON+=	Source/JavaScriptCore/wasm/generateWasm.py
REPLACE_PYTHON+=	Source/JavaScriptCore/wasm/generateWasmB3IRGeneratorInlinesHeader.py
REPLACE_PYTHON+=	Source/JavaScriptCore/wasm/generateWasmOpsHeader.py
REPLACE_PYTHON+=	Source/JavaScriptCore/wasm/generateWasmValidateInlinesHeader.py
REPLACE_PYTHON+=	Source/JavaScriptCore/yarr/create_regex_tables
REPLACE_PYTHON+=	Source/JavaScriptCore/yarr/generateYarrCanonicalizeUnicode
REPLACE_PYTHON+=	Source/ThirdParty/gtest/run_tests.py
REPLACE_PYTHON+=	Source/ThirdParty/gtest/scripts/fuse_gtest_files.py
REPLACE_PYTHON+=	Source/ThirdParty/gtest/scripts/gen_gtest_pred_impl.py
REPLACE_PYTHON+=	Source/ThirdParty/gtest/scripts/pump.py
REPLACE_PYTHON+=	Source/ThirdParty/gtest/scripts/upload.py
REPLACE_PYTHON+=	Source/ThirdParty/gtest/scripts/upload_gtest.py
REPLACE_PYTHON+=	Source/ThirdParty/gtest/test/gtest_break_on_failure_unittest.py
REPLACE_PYTHON+=	Source/ThirdParty/gtest/test/gtest_color_test.py
REPLACE_PYTHON+=	Source/ThirdParty/gtest/test/gtest_env_var_test.py
REPLACE_PYTHON+=	Source/ThirdParty/gtest/test/gtest_filter_unittest.py
REPLACE_PYTHON+=	Source/ThirdParty/gtest/test/gtest_help_test.py
REPLACE_PYTHON+=	Source/ThirdParty/gtest/test/gtest_list_tests_unittest.py
REPLACE_PYTHON+=	Source/ThirdParty/gtest/test/gtest_nc_test.py
REPLACE_PYTHON+=	Source/ThirdParty/gtest/test/gtest_output_test.py
REPLACE_PYTHON+=	Source/ThirdParty/gtest/test/gtest_shuffle_test.py
REPLACE_PYTHON+=	Source/ThirdParty/gtest/test/gtest_test_utils.py
REPLACE_PYTHON+=	Source/ThirdParty/gtest/test/gtest_throw_on_failure_test.py
REPLACE_PYTHON+=	Source/ThirdParty/gtest/test/gtest_uninitialized_test.py
REPLACE_PYTHON+=	Source/ThirdParty/gtest/test/gtest_xml_outfiles_test.py
REPLACE_PYTHON+=	Source/ThirdParty/gtest/test/gtest_xml_output_unittest.py
REPLACE_PYTHON+=	Source/ThirdParty/gtest/test/gtest_xml_test_utils.py
REPLACE_PYTHON+=	Source/ThirdParty/gtest/test/run_tests_util_test.py
REPLACE_PYTHON+=	Source/ThirdParty/gtest/xcode/Scripts/versiongenerate.py
REPLACE_PYTHON+=	Source/WebCore/PAL/AVFoundationSupport.py
REPLACE_PYTHON+=	Source/WebCore/css/makeSelectorPseudoClassAndCompatibilityElementMap.py
REPLACE_PYTHON+=	Source/WebCore/css/makeSelectorPseudoElementsMap.py
REPLACE_PYTHON+=	Source/WebCore/html/parser/create-html-entity-table
REPLACE_PYTHON+=	Source/WebCore/platform/network/create-http-header-name-table
REPLACE_PYTHON+=	Source/WebKit/Scripts/generate-message-receiver.py
REPLACE_PYTHON+=	Source/WebKit/Scripts/generate-messages-header.py
REPLACE_PYTHON+=	Tools/glib/common.py
REPLACE_PYTHON+=	Tools/glib/generate-inspector-gresource-manifest.py
REPLACE_PYTHON+=	Tools/gtk/*.py
REPLACE_PYTHON+=	Tools/gtk/generate-gtkdoc

SUBST_CLASSES+=		python
SUBST_FILES.python+=	Source/WebInspectorUI/Scripts/copy-user-interface-resources.pl
SUBST_SED.python+=	-e 's,\(.\)python.;,\1${PYTHONBIN}\1;,'
SUBST_STAGE.python=	pre-configure
SUBST_MESSAGE.python=	Fixing path to python binary.

.include "../../lang/ruby/rubyversion.mk"
BUILD_DEPENDS+=	${RUBY_BASE}>=${RUBY_VERSION}:${RUBY_SRCDIR}
CMAKE_ARGS+=	-DRUBY_EXECUTABLE=${RUBY}

PYTHON_FOR_BUILD_ONLY=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # not yet ported as of 1.10.2
.include "../../lang/python/application.mk"
CMAKE_ARGS+=	-DPYTHON_EXECUTABLE=${PYTHONBIN}

CXXFLAGS.SunOS+=	-fpermissive

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CXXFLAGS+=	-Wno-c++11-narrowing
.endif

# This does not disable optimisations, merely avoids #error if there are none.
CFLAGS+=	-DRELEASE_WITHOUT_OPTIMIZATIONS

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
