# $NetBSD: Makefile,v 1.10 2001/12/23 19:33:18 jlam Exp $

DISTNAME=	curl-7.9.1
CATEGORIES=	www
MASTER_SITES=	http://curl.haxx.se/download/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://curl.haxx.se/
COMMENT=	client that groks URLs

USE_BUILDLINK_ONLY=	yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_DIR}

# This causes curl-config not to be regenerated during build-time as it was
# already created at configure-time.
#
AUTOMAKE_POST_PATTERNS+=	curl-config

.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
