# $NetBSD: Makefile,v 1.37.2.2 2010/09/11 16:10:03 spz Exp $
#

DISTNAME=	seamonkey-${SM_VER}.source
PKGNAME=	seamonkey-${SM_VER}
SM_VER=		2.0.7
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_MOZILLA:=seamonkey/releases/${SM_VER}/source/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tnn@NetBSD.org
HOMEPAGE=	http://www.mozilla.org/projects/seamonkey/
COMMENT=	Full featured gecko-based browser

WRKSRC=		${WRKDIR}/comm-1.9.1
MOZILLA_DIR=	mozilla/

CONFIG_GUESS_OVERRIDE+=	directory/c-sdk/config/autoconf/config.guess
CONFIG_SUB_OVERRIDE+=	directory/c-sdk/config/autoconf/config.sub

CONFIGURE_ARGS+=	--enable-application=suite
CONFIGURE_ARGS+=	--enable-static

ALL_ENV+=		MOZILLA_PKG_NAME=seamonkey

pre-configure:
	cd ${WRKSRC}/directory/c-sdk && ${SETENV} ${CONFIGURE_ENV} autoconf
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} autoconf
	cd ${WRKSRC}/mozilla && ${SETENV} ${CONFIGURE_ENV} autoconf
	cd ${WRKSRC}/mozilla/js/src && ${SETENV} ${CONFIGURE_ENV} autoconf
	cd ${WRKSRC}/mozilla/nsprpub && ${SETENV} ${CONFIGURE_ENV} autoconf
	cd ${WRKSRC}/directory/c-sdk && ${SETENV} ${CONFIGURE_ENV} autoconf

do-build:
# XXX for some reason it doesn't work unless -j is explicitly specified
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} -j${MAKE_JOBS:U1}


.include "../../devel/xulrunner/mozilla-common.mk"
.include "options.mk"
.include "../../mk/bsd.pkg.mk"
