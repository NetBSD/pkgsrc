# $NetBSD: Makefile,v 1.199 2018/08/16 18:54:32 adam Exp $

DISTNAME=	curl-7.61.0
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	https://curl.haxx.se/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://curl.haxx.se/
COMMENT=	Client that groks URLs
# not completely, but near enough
LICENSE=	mit

# list it into IPv6-ready packages
BUILD_DEFS+=	IPV6_READY

USE_TOOLS+=		nroff perl
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--with-ca-path=${SSLCERTS}
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}
PKGCONFIG_OVERRIDE=	libcurl.pc.in

INSTALLATION_DIRS=	share/doc/curl

.include "../../mk/bsd.prefs.mk"

TEST_TARGET=		check

.include "options.mk"

post-install:
.for f in MANUAL TheArtOfHttpScripting FAQ
	${INSTALL_DATA} ${WRKSRC}/docs/${f} ${DESTDIR}${PREFIX}/share/doc/curl/
.endfor

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
