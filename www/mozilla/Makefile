# $NetBSD: Makefile,v 1.76 2001/11/14 23:03:38 enami Exp $

MOZ_VER=	0.9.5
NB_VER=		nb1
DISTNAME=	mozilla-source-${MOZ_VER}
PKGNAME=	mozilla-${MOZ_VER}${NB_VER}
WRKSRC=		${WRKDIR}/mozilla
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.mozilla.org/pub/mozilla/releases/mozilla${MOZ_VER}/src/ \
		ftp://ftp.fu-berlin.de/pub/unix/network/www/mozilla/releases/mozilla${MOZ_VER}/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.mozilla.org/
COMMENT=	The open-source version of the Netscape browser

BUILD_DEPENDS+=	perl>=${PERL5_REQD}:../../lang/perl5
BUILD_DEPENDS+=	zip>=2.3:../../archivers/zip

USE_GMAKE=	yes
USE_X11BASE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-tests \
		--disable-debug \
		--with-jpeg=${BUILDLINK_DIR} \
		--with-png=${BUILDLINK_DIR} \
		--enable-mathml \
		--enable-svg \
		--enable-crypto

.include	"../../x11/gtk/buildlink.mk"
.include	"../../graphics/gdk-pixbuf/buildlink.mk"
.include	"../../net/ORBit/buildlink.mk"
.include	"../../graphics/jpeg/buildlink.mk"
.include	"../../graphics/png/buildlink.mk"

ONLY_FOR_PLATFORM=	NetBSD-1.4[Y-Z]-i386 NetBSD-1.4Z[A-Z]-i386 \
			NetBSD-1.5_ALPHA-i386 NetBSD-1.5_BETA-* \
			NetBSD-1.[5-9]*-* Linux-*-*

MOZ_LIBDIR=	${PREFIX}/lib/mozilla
MAKE_ENV+=	LIBRUNPATH=${MOZ_LIBDIR}
CONFIGURE_ENV+=	LIBRUNPATH=${MOZ_LIBDIR}
LDFLAGS+=	-Wl,-R${MOZ_LIBDIR}

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
SHAREMODE?=	644

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "NetBSD")
CONFIGURE_ARGS+= --without-pthreads
.endif

.if  ${MACHINE_ARCH} == "m68k"
DBG=
.else
CONFIGURE_ARGS+= --enable-optimize
.endif

XPTCFILES+=	xptcinvoke_asm_sparc64_netbsd.s xptcstubs_asm_sparc64_netbsd.s
XPTCFILES+=	xptcinvoke_sparc64_netbsd.cpp xptcstubs_sparc64_netbsd.cpp

post-extract:
.for F in ${XPTCFILES}
	${CP} ${FILESDIR}/${F} ${WRKSRC}/xpcom/reflect/xptcall/src/md/unix/${F}
.endfor

post-build:
	${ECHO} skin,install,select,classic/1.0 >> ${WRKSRC}/dist/bin/chrome/installed-chrome.txt
	${ECHO} locale,install,select,en-US >> ${WRKSRC}/dist/bin/chrome/installed-chrome.txt

do-install:
	${SETENV} ${SCRIPTS_ENV} ${SH} ${FILESDIR}/moz-install

.include "../../mk/bsd.pkg.mk"
