# $NetBSD: Makefile,v 1.101 2002/08/29 07:07:47 itojun Exp $

MOZ_VER=	1.1
DISTNAME=	mozilla-source-${MOZ_VER}
PKGNAME=	mozilla-${MOZ_VER}
WRKSRC=		${WRKDIR}/mozilla
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_MOZILLA:=mozilla${MOZ_VER}/src/}
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	taya@netbsd.org
HOMEPAGE=	http://www.mozilla.org/
COMMENT=	Open-source version of the Netscape browser

BUILD_DEPENDS+=	zip>=2.3:../../archivers/zip
BUILD_DEPENDS+=	autoconf-2.13:../../devel/autoconf

USE_PERL5=	build
USE_GMAKE=	yes
USE_X11BASE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-tests \
		--disable-debug \
		--with-system-jpeg=${BUILDLINK_DIR} \
		--with-system-png=${BUILDLINK_DIR} \
		--enable-mathml \
		--enable-crypto \
		--enable-svg

SHAREMODE?=	644
ALL_TARGET=

UNLIMIT_RESOURCES=  datasize memorysize stacksize

.include	"../../x11/gtk/buildlink.mk"
.include	"../../graphics/gdk-pixbuf/buildlink.mk"
.include	"../../net/ORBit/buildlink.mk"
.include	"../../graphics/jpeg/buildlink.mk"
.include	"../../graphics/png/buildlink.mk"
.include	"../../graphics/freetype2/buildlink.mk"

# NetBSD-*-m68k builds, but "regchrome" dumps core.
NOT_FOR_PLATFORM=	NetBSD-1.4.*-* NetBSD-*-m68k

MOZ_LIBDIR=	${PREFIX}/lib/mozilla
MAKE_ENV+=	LIBRUNPATH=${MOZ_LIBDIR}
CONFIGURE_ENV+=	LIBRUNPATH=${MOZ_LIBDIR}
MAKE_ENV+=	MOZ_INTERNAL_LIBART_LGPL=1
CONFIGURE_ENV+=	MOZ_INTERNAL_LIBART_LGPL=1
LDFLAGS+=	-Wl,-R${MOZ_LIBDIR}

# avoid creating a .mozilla directory in the users home
# directory
SCRIPTS_ENV+=	HOME="${WRKDIR}"

PLIST_SRC=      ${PKGDIR}/PLIST-${OBJECT_FMT}

SCRIPTS_ENV+=	OBJECT_FMT=${OBJECT_FMT}
SCRIPTS_ENV+=	PLIST_SRC=${PLIST_SRC}
SCRIPTS_ENV+=	SED=${SED}
SCRIPTS_ENV+=	EGREP=${EGREP}
SCRIPTS_ENV+=	CHOWN=${CHOWN}
SCRIPTS_ENV+=	CHGRP=${CHGRP}
SCRIPTS_ENV+=	CHMOD=${CHMOD}
SCRIPTS_ENV+=	BINOWN=${BINOWN}
SCRIPTS_ENV+=	BINGRP=${BINGRP}
SCRIPTS_ENV+=	BINMODE=${BINMODE}
SCRIPTS_ENV+=	SETENV=${SETENV}

PTHREAD_OPTS+=	native optional

COPTS?=		-O2
CONFIGURE_ARGS+= --enable-optimize="${COPTS}"

XPTCFILES+=	xptcinvoke_asm_sparc64_netbsd.s xptcstubs_asm_sparc64_netbsd.s
XPTCFILES+=	xptcinvoke_sparc64_netbsd.cpp xptcstubs_sparc64_netbsd.cpp

post-extract:
.for F in ${XPTCFILES}
	${CP} ${FILESDIR}/${F} ${WRKSRC}/xpcom/reflect/xptcall/src/md/unix/${F}
.endfor

pre-configure:
	cd ${WRKSRC} && autoconf

post-build:
	${ECHO} skin,install,select,classic/1.0 >> ${WRKSRC}/dist/bin/chrome/installed-chrome.txt
	${ECHO} locale,install,select,en-US >> ${WRKSRC}/dist/bin/chrome/installed-chrome.txt

do-install:
	${SETENV} ${SCRIPTS_ENV} ${SH} ${FILESDIR}/moz-install

.include "../../mk/pthread.buildlink.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "none")
CONFIGURE_ARGS+= --without-pthreads
.endif

.include "../../mk/bsd.pkg.mk"
