# $NetBSD: Makefile,v 1.40 2000/09/03 18:36:06 martin Exp $

DISTNAME=	mozilla-source-M17
PKGNAME=	mozilla-1.0m17
WRKSRC=		${WRKDIR}/mozilla
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.mozilla.org/pub/mozilla/releases/m17/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.mozilla.org/

BUILD_DEPENDS+=	${LOCALBASE}/bin/perl:../../lang/perl5
BUILD_DEPENDS+=	autoconf:../../devel/autoconf
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
		--with-png=${LOCALBASE}
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

pre-configure:
	(cd ${WRKSRC} && autoconf)

post-build:
	(cd ${WRKSRC}/dist/bin && \
	${SETENV} LD_LIBRARY_PATH=. MOZILLA_FIVE_HOME=. ./regxpcom && \
	${SETENV} LD_LIBRARY_PATH=. MOZILLA_FIVE_HOME=. ./regchrome )

do-install:
	 ${SETENV} ${SCRIPTS_ENV} ${SCRIPTDIR}/moz-install

.include "../../mk/bsd.pkg.mk"
