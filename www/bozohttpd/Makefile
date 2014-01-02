# $NetBSD: Makefile,v 1.78 2014/01/02 09:02:22 mrg Exp $
#

DISTNAME=	bozohttpd-20140102
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	mrg@eterna.com.au
HOMEPAGE=	http://www.eterna.com.au/bozohttpd/
COMMENT=	Bozotic HTTP server; small and secure

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "options.mk"

# This package is IP family agnostic.
BUILD_DEFS+=		IPV6_READY

MAKE_FILE=		Makefile.boot

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing paths in manual page.
SUBST_STAGE.paths=	pre-build
SUBST_FILES.paths=	bozohttpd.8
SUBST_SED.paths=	-e "s|/usr/pkg/|"${PREFIX:Q}"/|g"

INSTALLATION_DIRS=	libexec ${PKGMANDIR}/man8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bozohttpd ${DESTDIR}${PREFIX}/libexec
	${INSTALL_MAN} ${WRKSRC}/bozohttpd.8 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
