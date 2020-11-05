# $NetBSD: Makefile,v 1.49 2020/11/05 09:09:19 ryoon Exp $

DISTNAME=	cliqz-1.38.0
PKGREVISION=	4
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=cliqz-oss/}
GITHUB_PROJECT=	browser-f
DISTFILES=	adult-domains.bin \
		cliqz@cliqz.com.xpi \
		dat@cliqz.com.xpi \
		https-everywhere@cliqz.com.xpi \
		gdprtool@cliqz.com.xpi \
		${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	${PKGNAME_NOREV}

CLIQZ_CHANNEL=		release
# If the PKGVERSION_NOREV is updated, make sure to update the last build id from
# ftp -Vo - https://repository.cliqz.com/dist/${CLIQZ_CHANNEL}/${PKGVERSION_NOREV}/lastbuildid
CLIQZ_LAST_BUILD_ID=	20200721193739
CLIQZ_PLUGIN_SUFX=	@cliqz.com.xpi

SITES.adult-domains.bin= \
	https://s3.amazonaws.com/cdn.cliqz.com/browser-f/APT/
SITES.cliqz${CLIQZ_PLUGIN_SUFX}= \
	https://repository.cliqz.com/dist/${CLIQZ_CHANNEL}/${PKGVERSION_NOREV}/${CLIQZ_LAST_BUILD_ID}/
SITES.dat${CLIQZ_PLUGIN_SUFX}= \
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
# cliqz (which is based on firefox) needs a compiler that supports
# gnu++14 and gnu++17.  However, passing --std=gnu++17 (from wrappers,
# as a result of USE_LANGUAGES), results in problems for some Rust
# modules (as of 74.0).  Therefore, do not declare the languages that
# are actually needed.
# \todo In pkgsrc infrastructure, separate the concept of needing a
# compiler that can implement a standard, and the concept of forcibly
# adding a --std flag.  (The build system of a package should be
# setting the --std flag that is needed, rather than relying on the
# defaults of a particular compiler version.)
# NB: Even when building cliqz (which is based on firefox) with
# PKGSRC_COMPILER=gcc, the package will depend on and use clang, doing
# so outside the normal compiler selection framework.
USE_LANGUAGES+=	c99 c++

.include "mozilla-common.mk"
.include "options.mk"

# Build script does not support python 3.x yet.
# https://firefox-source-docs.mozilla.org/build/buildsystem/python.html
PYTHON_VERSIONS_ACCEPTED=	27
PYTHON_FOR_BUILD_ONLY=		tool
TOOL_DEPENDS+=			cbindgen>=0.14.2:../../devel/cbindgen
TOOL_DEPENDS+=			nodejs-[0-9]*:../../lang/nodejs

.if !empty(PYTHON_VERSION_DEFAULT:M3[6789])
TOOL_DEPENDS+=			python${PYTHON_VERSION_DEFAULT}-[0-9]*:../../lang/python${PYTHON_VERSION_DEFAULT}
ALL_ENV+=			PYTHON3=${PREFIX}/bin/python${PYTHON_VERSION_DEFAULT:S/3/3./}
.else
TOOL_DEPENDS+=			python37-[0-9]*:../../lang/python37
ALL_ENV+=			PYTHON3=${PREFIX}/bin/python3.7
.endif

# Depend on Python3 sqlite3 module.
.if !empty(PYTHON_VERSION_DEFAULT:M3[6789])
BUILD_DEPENDS+=			py${PYTHON_VERSION_DEFAULT}-sqlite3-[0-9]*:../../databases/py-sqlite3
.else
BUILD_DEPENDS+=			py37-sqlite3-[0-9]*:../../databases/py-sqlite3
.endif

BUILD_DEPENDS+=			yasm>=1.1:../../devel/yasm
BUILD_DEPENDS+=			nasm>=2.14:../../devel/nasm

WRKSRC=			${WRKDIR}/${GITHUB_PROJECT}-${PKGVERSION_NOREV}

CLIQZ_ICON=		cliqz.png
CLIQZ_ICON_SRC=		${WRKSRC}/mozilla-release/browser/branding/cliqz/default48.png
MOZ_DESKTOP=		${WRKSRC}/mozilla-release/toolkit/mozapps/installer/linux/rpm/mozilla.desktop
CLIQZ_DESKTOP=		${WRKSRC}/mozilla-release/toolkit/mozapps/installer/linux/rpm/cliqz.desktop

MAKE_ENV+=	CQZ_RELEASE_CHANNEL=${CLIQZ_CHANNEL}
MAKE_ENV+=	CQZ_BUILD_ID=${CLIQZ_LAST_BUILD_ID}
MAKE_ENV+=	MOZBUILD_STATE_PATH=${WRKDIR}/.home/.mozbuild

CHECK_WRKREF_SKIP+=	lib/cliqz/chrome/toolkit/content/global/buildconfig.html

REPLACE_BASH+=	magic_build_and_package.sh

CFLAGS+=	-D_GLIBCXX_INCLUDE_NEXT_C_HEADERS
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/cliqz ${COMPILER_RPATH_FLAG}${PREFIX}/lib

# Needed by the Javascript JIT used in cliqz
NOT_PAX_MPROTECT_SAFE+=	lib/cliqz/cliqz
NOT_PAX_MPROTECT_SAFE+=	lib/cliqz/cliqz-bin
NOT_PAX_MPROTECT_SAFE+=	lib/cliqz/plugin-container

#
# Generate list of subst entries for various .cargo-checksum.json files.  These
# are all handled together in one big substitution to simplify things rather
# than one substitution entry per file, but are kept separate below to ease
# updating and verification.
#

CKSUM_CRATES+=	mozilla-release/third_party/rust/libc

# patch-third__party_rust_libc_src_unix_bsd_netbsdlike_netbsd_mod.rs
CKSUMS+=	a3540eab4dbc52e006e84e288bad17e1dae3865fea49020e0ed8b5a7724a9532
CKSUMS+=	5e58a2109f5eff0f497dfac150c161c1d517a2227b49e086da96c3d66522ac3a

CKSUM_CRATES+=	mozilla-release/third_party/rust/getrandom

# patch-third__party_rust_getrandom_src_lib.rs
CKSUMS+=	0e52f6bde42d7bb05c297ce1c25b9879d61b28caba98f6226a152bff538db6c2
CKSUMS+=	394425b4ba03c21c494e64d993678f7014575b1e3d590b9ee452b5c2d83ec4ac

SUBST_CLASSES+=		cksum
SUBST_STAGE.cksum=	pre-configure
.for crate in ${CKSUM_CRATES}
SUBST_FILES.cksum+=	${crate}/.cargo-checksum.json
.endfor
.for from to in ${CKSUMS}
SUBST_SED.cksum+=	-e 's,${from},${to},g'
.endfor

post-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/adult-domains.bin \
		${WRKSRC}/mozilla-release/browser/adult-domains.bin
	${MKDIR} ${WRKSRC}/obj/dist/bin/browser/features
	${CP} ${DISTDIR}/${DIST_SUBDIR}/cliqz${CLIQZ_PLUGIN_SUFX} \
		${DISTDIR}/${DIST_SUBDIR}/dat${CLIQZ_PLUGIN_SUFX} \
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
	${RUN}cd ${WRKSRC} && ${_ULIMIT_CMD} ${SETENV} ${MAKE_ENV} ./magic_build_and_package.sh

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
.include "../../mk/compiler.mk"
# Force the use of clang from pkgsrc, regardless of the setting of
# PKGSRC_COMPILER.
# \todo This breaks the use of ccache, which should be fixed, probably
# by adding support for this kind of forcing to pkgsrc infrastructure.
PKG_CC=		${PREFIX}/bin/clang
PKG_CXX=	${PREFIX}/bin/clang++
BUILDLINK_DEPMETHOD.clang=     build
.include "../../lang/clang/buildlink3.mk"
RUST_REQ=	1.41.0
.include "../../lang/rust/rust.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
