# $NetBSD: Makefile,v 1.13 2009/07/07 19:06:56 joerg Exp $
#

DISTNAME=	lhs-0.1
PKGREVISION=	4
CATEGORIES=	www
MASTER_SITES=	ftp://dev.null.pl/pub/

MAINTAINER=	dawszy@arhea.net
HOMEPAGE=	http://dev.null.pl/
COMMENT=	Lightweight HTTP Server, IPv6-aware and SSL-enabled

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/lhs
GNU_CONFIGURE=	yes

BUILD_DEFS+=	IPV6_READY

MAKE_ENV+=	OPENSSL_ROOT=${BUILDLINK_PREFIX.openssl}
MAKE_ENV+=	DEFAULT_ROOT_DIR=${PREFIX}/share/httpd/htdocs

INSTALLATION_DIRS=	sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lhs ${DESTDIR}${PREFIX}/sbin/lhs

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
