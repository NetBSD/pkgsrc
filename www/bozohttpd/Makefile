# $NetBSD: Makefile,v 1.47 2004/10/03 00:18:25 tv Exp $
#

DISTNAME=	bozohttpd-20040823
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	mrg@eterna.com.au
HOMEPAGE=	http://www.eterna.com.au/bozohttpd/
COMMENT=	Bozotic HTTP server; small and secure

BUILD_DEFS+=	USE_INET6

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	YES

.include "../../mk/bsd.prefs.mk"

.if defined(USE_INET6) && ${USE_INET6} == "YES"
CPPFLAGS+=	-DINET6
.endif
CPPFLAGS+=	-Wno-error
MAKE_ENV+=	BINDIR=${PREFIX}/libexec MANDIR=${PREFIX}/man

INSTALLATION_DIRS=	libexec man/cat8 man/man8

.include "../../security/openssl/buildlink3.mk"

pre-build:
	cd ${WRKSRC}; for file in bozohttpd.8; do			\
		${SED}	-e "s|/usr/pkg/|${PREFIX}/|g"			\
			$${file} >> $${file}.fixed;			\
		${MV} -f $${file}.fixed $${file};			\
	done

.include "../../mk/bsd.pkg.mk"
