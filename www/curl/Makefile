# $NetBSD: Makefile,v 1.18 2002/04/21 12:07:45 shell Exp $

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

USE_BUILDLINK_ONLY=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_DIR}

# This causes curl-config not to be regenerated during build-time as it was
# already created at configure-time.
#
AUTOMAKE_POST_PATTERNS+=	curl-config

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
	
.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
