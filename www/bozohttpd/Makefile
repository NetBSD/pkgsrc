# $NetBSD: Makefile,v 1.85 2016/03/05 11:29:35 jperkin Exp $
#

DISTNAME=	bozohttpd-20150320
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	mrg@eterna.com.au
HOMEPAGE=	http://www.eterna.com.au/bozohttpd/
COMMENT=	Bozotic HTTP server; small and secure

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

LDFLAGS.SunOS+=		-lsocket -lnsl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bozohttpd ${DESTDIR}${PREFIX}/libexec
	${INSTALL_MAN} ${WRKSRC}/bozohttpd.8 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
