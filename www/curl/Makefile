# $NetBSD: Makefile,v 1.13 2002/02/19 05:48:07 itojun Exp $

DISTNAME=	curl-7.9.2
CATEGORIES=	www
MASTER_SITES=	http://curl.haxx.se/download/ \
		ftp://ftp.sunet.se/pub/www/utilities/curl/ \
		ftp://ftp.rge.com/pub/networking/curl/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://curl.haxx.se/
COMMENT=	client that groks URLs

# list it into IPv6-ready packages
BUILD_DEFS+=	USE_INET6

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
