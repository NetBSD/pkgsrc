# $NetBSD: Makefile,v 1.33 2003/12/07 13:28:33 wiz Exp $

DISTNAME=	curl-7.10.8
CATEGORIES=	www
MASTER_SITES=	http://curl.haxx.se/download/ \
		ftp://ftp.sunet.se/pub/www/utilities/curl/ \
		ftp://ftp.rge.com/pub/networking/curl/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://curl.haxx.se/
COMMENT=	Client that groks URLs

# list it into IPv6-ready packages
BUILD_DEFS+=	USE_INET6

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}

.include "../../mk/bsd.prefs.mk"

.if empty(USE_INET6:M[yY][eE][sS])
CONFIGURE_ARGS+=	--disable-ipv6
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/curl
	for _f in MANUAL TheArtOfHttpScripting FAQ		\
		libcurl-the-guide; do				\
		${INSTALL_DATA} ${WRKSRC}/docs/$${_f}		\
			 ${PREFIX}/share/doc/curl/${_f};	\
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/curl
	for _f in ${WRKSRC}/docs/examples/*.c				\
		${WRKSRC}/docs/examples/README; do			\
		${INSTALL_DATA} $${_f} ${PREFIX}/share/examples/curl;	\
	done

.include "../../devel/zlib/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
