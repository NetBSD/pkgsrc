# $NetBSD: Makefile,v 1.161 2016/03/05 11:27:57 jperkin Exp $

DISTNAME=	curl-7.47.1
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	https://curl.haxx.se/download/ \
		ftp://ftp.sunet.se/pub/www/utilities/curl/
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

.if !empty(PKGSRC_RUN_TEST:M[Yy][Ee][Ss])
TEST_TARGET=		check
USE_TOOLS+=		perl
.endif

.if ${_USE_DESTDIR} == "no"
PRIVILEGED_STAGES+=	clean
.endif

.include "options.mk"

post-install:
.for f in MANUAL TheArtOfHttpScripting FAQ
	${INSTALL_DATA} ${WRKSRC}/docs/${f} ${DESTDIR}${PREFIX}/share/doc/curl/
.endfor

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
