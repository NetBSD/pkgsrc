# $NetBSD: Makefile,v 1.44 2000/10/26 07:53:37 mycroft Exp $

DISTNAME=	mozilla-source-M18
PKGNAME=	mozilla-0.m18
WRKSRC=		${WRKDIR}/mozilla
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.mozilla.org/pub/mozilla/releases/m18/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.mozilla.org/

BUILD_DEPENDS+=	${LOCALBASE}/bin/perl:../../lang/perl5
BUILD_DEPENDS+=	autoconf:../../devel/autoconf
BUILD_DEPENDS+=	zip:../../archivers/zip
DEPENDS+=	gtk+>=1.2.8:../../x11/gtk
DEPENDS+=	ORBit>=0.5.1:../../net/ORBit
DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	png>=1.0.6:../../graphics/png

USE_GMAKE=	yes
USE_X11BASE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-tests \
		--disable-debug \
		--enable-optimize \
		--with-jpeg=${LOCALBASE} \
		--with-png=${LOCALBASE} \
		--enable-mathml \
		--enable-svg

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
SHAREMODE?=	644

XPTCFILES+=	xptcinvoke_asm_ppc_netbsd.s xptcinvoke_ppc_netbsd.cpp
XPTCFILES+=	xptcstubs_asm_ppc_netbsd.s xptcstubs_ppc_netbsd.cpp
XPTCFILES+=	xptcinvoke_asm_sparc_netbsd.s xptcinvoke_sparc_netbsd.cpp
XPTCFILES+=	xptcstubs_asm_sparc_netbsd.s xptcstubs_sparc_netbsd.cpp

post-extract:
.for F in ${XPTCFILES}
	${CP} ${FILESDIR}/${F} ${WRKSRC}/xpcom/reflect/xptcall/src/md/unix/${F}
.endfor

pre-configure:
	(cd ${WRKSRC} && autoconf)

post-build:
	(cd ${WRKSRC}/dist/bin && \
	${SETENV} LD_LIBRARY_PATH=. MOZILLA_FIVE_HOME=. ./regxpcom && \
	${SETENV} LD_LIBRARY_PATH=. MOZILLA_FIVE_HOME=. ./regchrome )

do-install:
	${SETENV} ${SCRIPTS_ENV} ${SCRIPTDIR}/moz-install

.include "../../mk/bsd.pkg.mk"
