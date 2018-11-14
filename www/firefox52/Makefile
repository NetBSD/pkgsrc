# $NetBSD: Makefile,v 1.34 2018/11/14 22:22:36 kleink Exp $

FIREFOX_VER=		${MOZ_BRANCH}${MOZ_BRANCH_MINOR}
MOZ_BRANCH=		52.9
MOZ_BRANCH_MINOR=	.0esr

DISTNAME=	firefox-${FIREFOX_VER}.source
PKGNAME=	firefox52-${MOZ_BRANCH}${MOZ_BRANCH_MINOR:S/b/beta/:S/esr//}
PKGREVISION=	9
CATEGORIES=	www
MASTER_SITES+=	${MASTER_SITE_MOZILLA:=firefox/releases/${FIREFOX_VER}/source/}
MASTER_SITES+=	${MASTER_SITE_MOZILLA_ALL:=firefox/releases/${FIREFOX_VER}/source/}
EXTRACT_SUFX=	.tar.xz

WRKSRC=		${WRKDIR}/${DISTNAME:S/.source//}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.mozilla.com/en-US/firefox/
COMMENT=	Web browser with support for extensions (version ${MOZ_BRANCH:C/\..*//})
LICENSE=	mpl-1.1

MOZILLA_DIR=	# empty

# Note: when updating remember to conditionalise about-background.png in PLIST
CONFIGURE_ARGS+=	--enable-application=browser

# workround for link of libxul.so etc.
LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib/firefox52 ${COMPILER_RPATH_FLAG}${PREFIX}/lib
LDFLAGS.SunOS+=		-lm

NOT_PAX_MPROTECT_SAFE+=	lib/firefox52/firefox
NOT_PAX_MPROTECT_SAFE+=	lib/firefox52/firefox-bin
NOT_PAX_MPROTECT_SAFE+=	lib/firefox52/plugin-container

ALL_ENV+=		MOZILLA_PKG_NAME=firefox52

# Avoid ld "invalid section index" errors.
BUILDLINK_TRANSFORM.SunOS+=	rm:-fdata-sections
BUILDLINK_TRANSFORM.SunOS+=	rm:-ffunction-sections

SUBST_CLASSES+=			dfly_malloc_h
SUBST_STAGE.dfly_malloc_h=	pre-configure
SUBST_MESSAGE.dfly_malloc_h=	Dont include malloc.h on dragonflybsd
SUBST_SED.dfly_malloc_h=	-e 's,HAVE_MALLOC_H,HAVE_MALLOC_H \&\& !defined(__DragonFly__),g'
SUBST_FILES.dfly_malloc_h=	media/libav/libavutil/mem.c
SUBST_FILES.dfly_malloc_h+=	media/ffvpx/libavutil/mem.c

LDFLAGS.DragonFly=	-lplc4 -lnspr4
LDFLAGS.FreeBSD=	-lplc4 -lnspr4
LDFLAGS.Linux=		-lnspr4

.include "mozilla-common.mk"
.include "options.mk"

CHECK_INTERPRETER_SKIP+=lib/firefox-sdk/sdk/bin/header.py
CHECK_INTERPRETER_SKIP+=lib/firefox-sdk/sdk/bin/typelib.py
CHECK_INTERPRETER_SKIP+=lib/firefox-sdk/sdk/bin/xpidl.py
CHECK_INTERPRETER_SKIP+=lib/firefox-sdk/sdk/bin/xpt.py

CHECK_WRKREF_SKIP+=lib/firefox52/chrome/toolkit/content/global/buildconfig.html

MOZILLA=firefox52
MOZILLA_ICON=	${WRKSRC}/${OBJDIR}/dist/firefox/browser/chrome/icons/default/default48.png
.if !empty(PKG_OPTIONS:Mofficial-mozilla-branding)
MOZILLA_NAME=	Firefox
.else
MOZILLA_NAME=	Browser
.endif

SUBST_CLASSES+=		sys-dic
SUBST_STAGE.sys-dic=	pre-configure
SUBST_MESSAGE.sys-dic=	Reference to system hunspell dictionaries.
SUBST_FILES.sys-dic=	extensions/spellcheck/hunspell/glue/mozHunspell.cpp
SUBST_VARS.sys-dic=	PREFIX

post-extract:
	mv ${WRKSRC}/gfx/ycbcr/yuv_row_arm.s ${WRKSRC}/gfx/ycbcr/yuv_row_arm.S

pre-configure:
	cd ${WRKSRC} && autoconf
	cd ${WRKSRC}/js/src && autoconf
	cd ${WRKSRC} && mkdir ${OBJDIR}
	cd ${WRKSRC}/${OBJDIR} && touch old-configure.vars

post-build:
	${SED} -e 's|@MOZILLA@|${MOZILLA}|g'				\
	  -e 's|@MOZILLA_NAME@|${MOZILLA_NAME}|g'			\
	  -e 's|@FIREFOX_ICON@|${MOZILLA}.png|g'			\
	  < ${FILESDIR}/desktop.in					\
	  > ${WRKDIR}/desktop

INSTALLATION_DIRS+=	share/applications share/pixmaps
post-install:
	${INSTALL_DATA} ${WRKDIR}/desktop				\
	  ${DESTDIR}${PREFIX}/share/applications/${MOZILLA}.desktop
	${INSTALL_DATA} ${MOZILLA_ICON}					\
	  ${DESTDIR}${PREFIX}/share/pixmaps/${MOZILLA}.png

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
