# $NetBSD: Makefile,v 1.31 2003/11/12 03:39:43 jschauma Exp $

DISTNAME=	curl-7.10.6
PKGREVISION=	1
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
