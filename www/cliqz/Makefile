# $NetBSD: Makefile,v 1.10 2019/06/08 00:56:22 fox Exp $

DISTNAME=	cliqz-1.27.0
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=cliqz-oss/}
GITHUB_PROJECT=	browser-f
GITHUB_TAG=	${PKGVERSION_NOREV}
DISTFILES=	adult-domains.bin \
		cliqz@cliqz.com.xpi \
		https-everywhere@cliqz.com.xpi \
		gdprtool@cliqz.com.xpi \
		${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	${PKGNAME_NOREV}

CLIQZ_CHANNEL=		release
# If the PKGVERSION_NOREV is updated, make sure to update the last build id from
# ftp -Vo - https://repository.cliqz.com/dist/${CLIQZ_CHANNEL}/${PKGVERSION_NOREV}/lastbuildid
CLIQZ_LAST_BUILD_ID=	20190603212344
CLIQZ_PLUGIN_SUFX=	@cliqz.com.xpi

SITES.adult-domains.bin= \
	https://s3.amazonaws.com/cdn.cliqz.com/browser-f/APT/
SITES.cliqz${CLIQZ_PLUGIN_SUFX}= \
	https://repository.cliqz.com/dist/${CLIQZ_CHANNEL}/${PKGVERSION_NOREV}/${CLIQZ_LAST_BUILD_ID}/
SITES.https-everywhere${CLIQZ_PLUGIN_SUFX}= \
	https://repository.cliqz.com/dist/${CLIQZ_CHANNEL}/${PKGVERSION_NOREV}/${CLIQZ_LAST_BUILD_ID}/
SITES.gdprtool${CLIQZ_PLUGIN_SUFX}= \
	https://repository.cliqz.com/dist/${CLIQZ_CHANNEL}/${PKGVERSION_NOREV}/${CLIQZ_LAST_BUILD_ID}/

EXTRACT_USING=	bsdtar
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	fox@NetBSD.org
HOMEPAGE=	https://cliqz.com/en/desktop
COMMENT=	Secure browser (Mozilla based) with built-in quick search
LICENSE=	mpl-2.0 AND gnu-gpl-v2

USE_TOOLS+=	pkg-config perl gmake autoconf213 unzip zip bash pax
USE_LANGUAGES+=	c99 gnu++14

# Build script does not support python 3.x yet.
# https://firefox-source-docs.mozilla.org/build/buildsystem/python.html
PYTHON_VERSIONS_ACCEPTED=	27
PYTHON_FOR_BUILD_ONLY=		tool
TOOL_DEPENDS+=			cbindgen>=0.8.2:../../devel/cbindgen
TOOL_DEPENDS+=			nodejs-[0-9]*:../../lang/nodejs

BUILD_DEPENDS+=			yasm>=1.1:../../devel/yasm
BUILD_DEPENDS+=			nasm-[0-9]*:../../devel/nasm

WRKSRC=			${WRKDIR}/${GITHUB_PROJECT}-${PKGVERSION_NOREV}

CLIQZ_ICON=		cliqz.png
CLIQZ_ICON_SRC=		${WRKSRC}/mozilla-release/browser/branding/cliqz/default48.png
MOZ_DESKTOP=		${WRKSRC}/mozilla-release/toolkit/mozapps/installer/linux/rpm/mozilla.desktop
CLIQZ_DESKTOP=		${WRKSRC}/mozilla-release/toolkit/mozapps/installer/linux/rpm/cliqz.desktop

MAKE_ENV+=	CQZ_RELEASE_CHANNEL=${CLIQZ_CHANNEL}
MAKE_ENV+=	CQZ_BUILD_ID=${CLIQZ_LAST_BUILD_ID}
MAKE_ENV+=	MOZBUILD_STATE_PATH=${WRKDIR}/.home/.mozbuild

.include "mozilla-common.mk"
.include "options.mk"

CHECK_WRKREF_SKIP+=	lib/cliqz/chrome/toolkit/content/global/buildconfig.html

REPLACE_BASH+=	magic_build_and_package.sh

CFLAGS+=	-D_GLIBCXX_INCLUDE_NEXT_C_HEADERS
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/cliqz ${COMPILER_RPATH_FLAG}${PREFIX}/lib

# Needed by the Javascript JIT used in cliqz
NOT_PAX_MPROTECT_SAFE+=	lib/cliqz/cliqz
NOT_PAX_MPROTECT_SAFE+=	lib/cliqz/cliqz-bin
NOT_PAX_MPROTECT_SAFE+=	lib/cliqz/plugin-container

post-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/adult-domains.bin ${WRKSRC}
	${MKDIR} ${WRKSRC}/obj/dist/bin/browser/features
	${CP} ${DISTDIR}/${DIST_SUBDIR}/cliqz${CLIQZ_PLUGIN_SUFX} \
		${DISTDIR}/${DIST_SUBDIR}/https-everywhere${CLIQZ_PLUGIN_SUFX} \
		${DISTDIR}/${DIST_SUBDIR}/gdprtool${CLIQZ_PLUGIN_SUFX} \
		${WRKSRC}/obj/dist/bin/browser/features

post-patch:
	${SED}  -e 's/@MOZ_APP_DISPLAYNAME@/Cliqz Internet/g' \
		-e 's/@MOZ_APP_NAME@/cliqz/g' \
		-e '/Icon=cliqz/ s/cliqz/${CLIQZ_ICON}/' \
		-e '/StartupWMClass/d' \
		< ${MOZ_DESKTOP} \
		> ${CLIQZ_DESKTOP}
	for MOZ_CONFIGURE_ARG in ${MOZ_CONFIGURE_ARGS}; do \
		${ECHO} $$MOZ_CONFIGURE_ARG >> \
			${WRKSRC}/mozilla-release/browser/config/cliqz.mozconfig; \
	done;

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./magic_build_and_package.sh

INSTALLATION_DIRS+=	share/applications share/pixmaps bin lib/cliqz
do-install:
	cd ${WRKSRC}/obj/dist/cliqz && \
		${PAX} -wr * ${DESTDIR}${PREFIX}/lib/cliqz && \
		${CHOWN} -R ${ROOT_USER}:${ROOT_GROUP} ${DESTDIR}${PREFIX}/lib/*
	cd ${DESTDIR}${PREFIX}/lib && \
		${FIND} . \(	-name \*.js  -or \
				-name \*.html -or \
				-name \*.xml -or \
				-name \*.svg \
			\) \
			-type f \
			-exec ${CHMOD} 0644 '{}' \;

post-install:
	${ECHO} '#! /bin/sh' > ${DESTDIR}${PREFIX}/bin/cliqz
	${ECHO} 'exec ${PREFIX}/lib/cliqz/cliqz "$$@"' >> ${DESTDIR}${PREFIX}/bin/cliqz
	${CHMOD} 755 ${DESTDIR}${PREFIX}/bin/cliqz
	${INSTALL_DATA} ${CLIQZ_DESKTOP} ${DESTDIR}${PREFIX}/share/applications/
	${INSTALL_DATA} ${CLIQZ_ICON_SRC} ${DESTDIR}${PREFIX}/share/pixmaps/${CLIQZ_ICON}

.include "../../lang/python/pyversion.mk"
BUILDLINK_DEPMETHOD.clang=     build
BUILDLINK_API_DEPENDS.clang+=  clang>=6.0.1nb1
.include "../../lang/clang/buildlink3.mk"
BUILDLINK_DEPMETHOD.rust=      build
BUILDLINK_API_DEPENDS.rust+=   rust>=1.31.0
.include "../../lang/rust/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
