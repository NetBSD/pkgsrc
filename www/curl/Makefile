# $NetBSD: Makefile,v 1.15 2002/03/15 08:18:45 itojun Exp $

DISTNAME=	curl-7.9.5
CATEGORIES=	www
MASTER_SITES=	http://curl.haxx.se/download/ \
		ftp://ftp.sunet.se/pub/www/utilities/curl/ \
		ftp://ftp.rge.com/pub/networking/curl/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://curl.haxx.se/
COMMENT=	client that groks URLs

# list it into IPv6-ready packages
.include "../../mk/bsd.prefs.mk"
BUILD_DEFS+=	USE_INET6

USE_BUILDLINK_ONLY=	yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_DIR}
.if defined(USE_INET6) && ${USE_INET6} == "YES"
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif
CONFIGURE_ARGS+=	--enable-debug

# This causes curl-config not to be regenerated during build-time as it was
# already created at configure-time.
#
AUTOMAKE_POST_PATTERNS+=	curl-config

.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
