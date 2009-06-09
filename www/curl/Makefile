# $NetBSD: Makefile,v 1.90 2009/06/09 18:31:35 wiz Exp $

DISTNAME=	curl-7.19.5
CATEGORIES=	www
MASTER_SITES=	http://curl.haxx.se/download/ \
		ftp://ftp.sunet.se/pub/www/utilities/curl/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://curl.haxx.se/
COMMENT=	Client that groks URLs
# not completely, but near enough
LICENSE=	mit

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

# list it into IPv6-ready packages
BUILD_DEFS+=	IPV6_READY

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}

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
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/curl
	for _f in MANUAL TheArtOfHttpScripting FAQ			\
		curl-config.pdf curl.pdf; do				\
		${INSTALL_DATA} ${WRKSRC}/docs/$${_f}			\
			 ${DESTDIR}${PREFIX}/share/doc/curl/${_f};	\
	done
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/curl
	for _f in ${WRKSRC}/docs/examples/*.c				\
		${WRKSRC}/docs/examples/README; do			\
		${INSTALL_DATA} $${_f} 					\
			${DESTDIR}${PREFIX}/share/examples/curl;	\
	done

.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
