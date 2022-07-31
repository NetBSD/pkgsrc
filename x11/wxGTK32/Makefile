# $NetBSD: Makefile,v 1.8 2022/07/31 16:57:22 wiz Exp $

DISTNAME=	wxWidgets-3.2.0
PKGNAME=	${DISTNAME:S/wxWidgets/wxGTK32/}
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=wxWidgets/}
GITHUB_PROJECT=	wxWidgets
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	dbj@NetBSD.org
HOMEPAGE=	https://www.wxwidgets.org/
COMMENT=	Cross-platform wxWidgets GUI library (3.2 stable branch)
# LGPLv2 with additional permission; http://opensource.org/licenses/wxwindows
LICENSE=	gnu-lgpl-v2

USE_TOOLS+=		pkg-config msgfmt
USE_LANGUAGES=		c c++

PLIST_SRC+=		${PLIST_SRC_DFLT}

DOCDIR=			share/wx-3.2/doc/wxWidgets

INSTALLATION_DIRS+=	${DOCDIR}
INSTALLATION_DIRS+=	bin

REPLACE_SH=		wx-config.in wx-config-inplace.in

.include "../../mk/bsd.prefs.mk"

# We build using configure by default
# The software supports building using cmake but
# the default cmake configuration is different.
# In particular, it doesn't install proper locale data
# and also installs unused headers.
#
# This option is expected to be a temporary hack.
# We should fix cmake builds to match configure builds
# and remove support for building with GNU_CONFIGURE
PKG_OPTIONS_VAR=	PKG_OPTIONS.wxGTK32
PKG_SUPPORTED_OPTIONS=	cmake
.if ${OPSYS} == "NetBSD"
PKG_SUGGESTED_OPTIONS=	cmake
.endif
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcmake)

USE_CMAKE=		yes
PLIST_SRC+=		PLIST.cmake

CMAKE_ARGS+=		-DCMAKE_DISABLE_PRECOMPILE_HEADERS:BOOL=ON
CMAKE_ARGS+=		-DCMAKE_INSTALL_BINDIR:PATH=libexec/wx-3.2
.  if ${OPSYS} != "Linux"
# https://github.com/wxWidgets/wxWidgets/issues/22646
CMAKE_ARGS+=		-DwxUSE_JOYSTICK:BOOL=OFF
.  endif

SUBST_CLASSES+=		unwrap
SUBST_STAGE.unwrap=	post-build
SUBST_MESSAGE.unwrap=	Unwrapping wx-config.
.  if ${OPSYS} != "Darwin"
SUBST_FILES.unwrap=	lib/wx/config/gtk3-unicode-3.2
.  else
SUBST_FILES.unwrap=	lib/wx/config/osx_cocoa-unicode-3.2
.  endif
SUBST_SED.unwrap=	-e 's,EGREP=.*,EGREP=${EGREP},'
SUBST_SED.unwrap+=	-e 's,echo.*/${CC}",echo "${CC}",'
SUBST_SED.unwrap+=	-e 's,echo.*/${CXX}",echo "${CXX}",'
SUBST_SED.unwrap+=	-e 's,echo.*/${CXX} -o",echo "${CXX} -o",'

.else # empty(PKG_OPTIONS:Mcmake)

GNU_CONFIGURE=		yes
PLIST_SRC+=		PLIST.configure

USE_GNU_CONFIGURE_HOST=	no
CONFIGURE_ARGS+=	--with-libpng=sys
CONFIGURE_ARGS+=	--with-libjpeg=sys
CONFIGURE_ARGS+=	--with-libtiff=sys
CONFIGURE_ARGS+=	--with-opengl
CONFIGURE_ARGS+=	--with-expat=sys
CONFIGURE_ARGS+=	--with-zlib=sys
CONFIGURE_ARGS+=	--with-regex=sys
#CONFIGURE_ARGS+=	--disable-webview
CONFIGURE_ARGS+=	--enable-mediactrl
CONFIGURE_ARGS+=	--disable-precomp-headers
CONFIGURE_ARGS+=	--bindir=${PREFIX}/libexec/wx-3.2
CONFIGURE_ARGS+=	--datarootdir=${PREFIX}/share/wx-3.2
CONFIGURE_ARGS.Darwin+=	--with-osx_cocoa
CONFIGURE_ARGS.Darwin+=	--without-macosx-sdk
CONFIGURE_ARGS.Darwin+=	--without-macosx-version-min
CONFIGURE_ARGS.Darwin+=	--disable-precomp-headers
CONFIGURE_ARGS.SunOS+=	--disable-xlocale

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		configure
SUBST_SED.fix-paths=		-e 's,/usr/pkg/include,${PREFIX}/include,g'
SUBST_VARS.fix-paths=		PREFIX
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/licence.txt ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/lgpl.txt ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/changes.txt ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/readme.txt ${DESTDIR}${PREFIX}/${DOCDIR}
	${LN} -sf ../libexec/wx-3.2/wxrc ${DESTDIR}${PREFIX}/bin/wxrc-3.2
	${LN} -sf ../libexec/wx-3.2/wx-config ${DESTDIR}${PREFIX}/bin/wx-config-3.2

.if ${OPSYS} != "Darwin"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../textproc/gspell/buildlink3.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
PLIST_SRC+=	PLIST.gtk3
.endif

.include "../../archivers/libmspack/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../security/libsecret/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
