# $NetBSD: Makefile,v 1.18.2.2 2002/06/21 23:05:48 jlam Exp $

DISTNAME=	curl-7.9.6
CATEGORIES=	www
MASTER_SITES=	http://curl.haxx.se/download/ \
		ftp://ftp.sunet.se/pub/www/utilities/curl/ \
		ftp://ftp.rge.com/pub/networking/curl/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://curl.haxx.se/
COMMENT=	client that groks URLs

# list it into IPv6-ready packages
BUILD_DEFS+=	USE_INET6

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/curl
	for _f in MANUAL TheArtOfHttpScripting FAQ; do		\
		${INSTALL_DATA} ${WRKSRC}/docs/$${_f}		\
			 ${PREFIX}/share/doc/curl/${_f};	\
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/curl
	for _f in ${WRKSRC}/docs/examples/*.c ; do			\
		${INSTALL_DATA} $${_f} ${PREFIX}/share/examples/curl;	\
	done
	${SED} '/php/d' ${WRKSRC}/docs/examples/README >		\
		${PREFIX}/share/examples/curl/README
	
.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
