# $NetBSD: Makefile,v 1.455 2020/11/06 08:56:37 maya Exp $

FIREFOX_VER=		${MOZ_BRANCH}${MOZ_BRANCH_MINOR}
MOZ_BRANCH=		82.0
MOZ_BRANCH_MINOR=	.2

DISTNAME=	firefox-${FIREFOX_VER}.source
PKGNAME=	${DISTNAME:S/.source//:S/b/beta/:S/esr//}
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES+=	${MASTER_SITE_MOZILLA:=firefox/releases/${FIREFOX_VER}/source/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://www.mozilla.org/en-US/firefox/
COMMENT=	Web browser with support for extensions (version ${FIREFOX_VER:tu:C/\\.[[:digit:]\.]*//})
LICENSE=	mpl-1.1

UNLIMIT_RESOURCES+=	datasize virtualsize

WRKSRC=		${WRKDIR}/firefox-${FIREFOX_VER:C/b.*//}

MOZILLA_DIR=	# empty

# Note: when updating remember to conditionalise about-background.png in PLIST
CONFIGURE_ARGS+=	--enable-application=browser

#CFLAGS+=	-I${PREFIX}/include/nspr
# for lang/gcc6
CFLAGS+=	-D_GLIBCXX_INCLUDE_NEXT_C_HEADERS
CFLAGS.SunOS+=	-D_POSIX_PTHREAD_SEMANTICS

LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib/${PKGBASE}
LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib
LDFLAGS.DragonFly+=	-lplc4 -lnspr4
LDFLAGS.FreeBSD+=	-lplc4 -lnspr4
LDFLAGS.Linux+=		-lnspr4
LDFLAGS.SunOS+=		-lm

# XXX not sure how to test this! likely unnecessary
NOT_PAX_MPROTECT_SAFE+=	lib/${PKGBASE}/plugin-container

# Avoid ld "invalid section index" errors.
BUILDLINK_TRANSFORM.SunOS+=	rm:-fdata-sections
BUILDLINK_TRANSFORM.SunOS+=	rm:-ffunction-sections
BUILDLINK_TRANSFORM.SunOS+=	rm:-pie

# Workaround for https://bugs.llvm.org/show_bug.cgi?id=46366
BUILDLINK_TRANSFORM.NetBSD+=	rm:-fexperimental-new-pass-manager

SUBST_CLASSES+=			dfly_malloc_h
SUBST_STAGE.dfly_malloc_h=	pre-configure
SUBST_MESSAGE.dfly_malloc_h=	Dont include malloc.h on dragonflybsd
SUBST_SED.dfly_malloc_h=	-e 's,HAVE_MALLOC_H,HAVE_MALLOC_H \&\& !defined(__DragonFly__),g'
SUBST_FILES.dfly_malloc_h+=	media/ffvpx/libavutil/mem.c

.include "mozilla-common.mk"
.include "options.mk"

CHECK_INTERPRETER_SKIP+=	lib/firefox-sdk/sdk/bin/header.py
CHECK_INTERPRETER_SKIP+=	lib/firefox-sdk/sdk/bin/typelib.py
CHECK_INTERPRETER_SKIP+=	lib/firefox-sdk/sdk/bin/xpidl.py
CHECK_INTERPRETER_SKIP+=	lib/firefox-sdk/sdk/bin/xpt.py

CHECK_WRKREF_SKIP+=	lib/${MOZILLA}/chrome/toolkit/content/global/buildconfig.html

MOZILLA=	${PKGBASE}
MOZILLA_ICON=	${WRKSRC}/${OBJDIR}/dist/${MOZILLA}/browser/chrome/icons/default/default48.png
.if !empty(PKG_OPTIONS:Mofficial-mozilla-branding)
MOZILLA_NAME=	Firefox
.else
MOZILLA_NAME=	Browser
.endif

#
# Generate list of subst entries for various .cargo-checksum.json files.  These
# are all handled together in one big substitution to simplify things rather
# than one substitution entry per file, but are kept separate below to ease
# updating and verification.
#

#CKSUM_CRATES+=	third_party/rust/libc

# patch-third__party_rust_libc_src_unix_bsd_netbsdlike_netbsd_mod.rs 
#CKSUMS+=	a3540eab4dbc52e006e84e288bad17e1dae3865fea49020e0ed8b5a7724a9532
#CKSUMS+=	5e58a2109f5eff0f497dfac150c161c1d517a2227b49e086da96c3d66522ac3a

#CKSUM_CRATES+=	third_party/rust/getrandom

# patch-third__party_rust_getrandom_src_lib.rs
#CKSUMS+=	0e52f6bde42d7bb05c297ce1c25b9879d61b28caba98f6226a152bff538db6c2
#CKSUMS+=	394425b4ba03c21c494e64d993678f7014575b1e3d590b9ee452b5c2d83ec4ac

#SUBST_CLASSES+=		cksum
#SUBST_STAGE.cksum=	pre-configure
#.for crate in ${CKSUM_CRATES}
#SUBST_FILES.cksum+=	${crate}/.cargo-checksum.json
#.endfor
#.for from to in ${CKSUMS}
#SUBST_SED.cksum+=	-e 's,${from},${to},g'
#.endfor

post-extract:
	mv ${WRKSRC}/gfx/ycbcr/yuv_row_arm.s ${WRKSRC}/gfx/ycbcr/yuv_row_arm.S

pre-configure:
	cd ${WRKSRC} && autoconf
	cd ${WRKSRC}/js/src && autoconf
	cd ${WRKSRC} && mkdir ${OBJDIR}
	cd ${WRKSRC}/${OBJDIR} && touch old-configure.vars
	# Do not fetch Rust Cargo file via network during build

post-build:
	${SED} -e 's|@MOZILLA@|${MOZILLA}|g'				\
	  -e 's|@MOZILLA_NAME@|${MOZILLA_NAME}|g'			\
	  -e 's|@FIREFOX_ICON@|${MOZILLA}.png|g'			\
	  < ${FILESDIR}/desktop.in					\
	  > ${WRKDIR}/desktop

INSTALLATION_DIRS+=	share/applications share/pixmaps
post-install:
	${ECHO} '#! /bin/sh' > ${DESTDIR}${PREFIX}/bin/${MOZILLA}
	${ECHO} '${PREFIX}/lib/${MOZILLA}/${MOZILLA} "$$@"' >> \
		${DESTDIR}${PREFIX}/bin/${MOZILLA}
	${CHMOD} 755 ${DESTDIR}${PREFIX}/bin/${MOZILLA}
	${INSTALL_DATA} ${WRKDIR}/desktop				\
	  ${DESTDIR}${PREFIX}/share/applications/${MOZILLA}.desktop
	${INSTALL_DATA} ${MOZILLA_ICON}					\
	  ${DESTDIR}${PREFIX}/share/pixmaps/${MOZILLA}.png

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
