# $NetBSD: Makefile,v 1.5 2004/01/20 12:27:59 agc Exp $
#

DISTNAME=	lhs-0.1
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	ftp://dev.null.pl/pub/

MAINTAINER=	dawszy@arhea.net
HOMEPAGE=	http://dev.null.pl/
COMMENT=	Lightweight HTTP Server, IPv6-aware and SSL-enabled

WRKSRC=		${WRKDIR}/lhs
USE_BUILDLINK2=	yes
GNU_CONFIGURE=	yes

BUILD_DEFS+=	USE_INET6

MAKE_ENV+=	OPENSSL_ROOT=${BUILDLINK_PREFIX.openssl}
MAKE_ENV+=	DEFAULT_ROOT_DIR=${PREFIX}/share/httpd/htdocs

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lhs ${PREFIX}/sbin/lhs

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
