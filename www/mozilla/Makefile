# $NetBSD: Makefile,v 1.52 2001/01/16 16:01:21 taya Exp $

DISTNAME=	mozilla-source-0.7
PKGNAME=	mozilla-0.7
WRKSRC=		${WRKDIR}/mozilla
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.mozilla.org/pub/mozilla/releases/mozilla0.7/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.mozilla.org/

BUILD_DEPENDS+=	${PERL5}:../../lang/perl5-base
BUILD_DEPENDS+=	autoconf:../../devel/autoconf
BUILD_DEPENDS+=	zip:../../archivers/zip
DEPENDS+=	gtk+>=1.2.8:../../x11/gtk
DEPENDS+=	ORBit>=0.5.1:../../net/ORBit
DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	png>=1.0.6:../../graphics/png

ONLY_FOR_PLATFORM=	NetBSD-1.4[Y-Z]-i386 NetBSD-1.4Z[A-Z]-i386 \
			NetBSD-1.5_ALPHA-i386 NetBSD-1.5_BETA-* \
			NetBSD-1.[5-9]*-*

USE_GMAKE=	yes
USE_X11BASE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-tests \
		--disable-debug \
		--enable-optimize \
		--with-jpeg=${LOCALBASE} \
		--with-png=${LOCALBASE} \
		--enable-mathml \
		--enable-svg \
		--with-extensions=cookie,irc,wallet,xmlextras,xml-rpc

MOZ_LIBDIR=	${PREFIX}/lib/mozilla
MAKE_ENV+=	LIBRUNPATH=${MOZ_LIBDIR}
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

XPTCFILES+=	xptcinvoke_asm_ppc_netbsd.s xptcstubs_asm_ppc_netbsd.s
XPTCFILES+=	xptcinvoke_ppc_netbsd.cpp xptcstubs_ppc_netbsd.cpp
XPTCFILES+=	xptcinvoke_asm_sparc_netbsd.s xptcstubs_asm_sparc_netbsd.s
XPTCFILES+=	xptcinvoke_sparc_netbsd.cpp xptcstubs_sparc_netbsd.cpp
XPTCFILES+=	xptcinvoke_arm_netbsd.cpp xptcstubs_arm_netbsd.cpp

post-extract:
.for F in ${XPTCFILES}
	${CP} ${FILESDIR}/${F} ${WRKSRC}/xpcom/reflect/xptcall/src/md/unix/${F}
.endfor

.include "../../mk/bsd.prefs.mk"

pre-configure:
	(cd ${WRKSRC} && autoconf)

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS}
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} BUILD_MODULES=psm

post-build:
	${ECHO} skin,install,select,classic/1.0 >> ${WRKSRC}/dist/bin/chrome/installed-chrome.txt
	${ECHO} locale,install,select,en-US >> ${WRKSRC}/dist/bin/chrome/installed-chrome.txt

do-install:
	${SETENV} ${SCRIPTS_ENV} ${SCRIPTDIR}/moz-install

.include "../../mk/bsd.pkg.mk"
