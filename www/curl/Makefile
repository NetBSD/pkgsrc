# $NetBSD: Makefile,v 1.215 2019/08/11 13:24:18 wiz Exp $

DISTNAME=	curl-7.65.3
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	https://curl.haxx.se/download/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://curl.haxx.se/
COMMENT=	Client that groks URLs
# not completely, but near enough
LICENSE=	mit

BUILD_DEFS+=	IPV6_READY

USE_TOOLS+=		nroff perl
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--with-ca-path=${SSLCERTS}
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}
PKGCONFIG_OVERRIDE=	libcurl.pc.in
TEST_TARGET=		check

INSTALLATION_DIRS=	share/doc/curl

.include "options.mk"

post-install:
.for f in TheArtOfHttpScripting FAQ
	${INSTALL_DATA} ${WRKSRC}/docs/${f} ${DESTDIR}${PREFIX}/share/doc/curl/
.endfor

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
