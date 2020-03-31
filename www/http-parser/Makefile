# $NetBSD: Makefile,v 1.12 2020/03/31 17:01:13 wiz Exp $

DISTNAME=	http-parser-2.9.4
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=nodejs/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/nodejs/http-parser
COMMENT=	Parser for HTTP messages written in C
LICENSE=	mit

USE_LANGUAGES=		c
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake

INSTALLATION_DIRS=	include lib

BUILDLINK_TRANSFORM+=	rm:-Werror

do-build:
	cd ${WRKSRC} && ${LIBTOOL} --mode=compile --tag=CC ${CC} ${CFLAGS} \
	    -c http_parser.c
	cd ${WRKSRC} && ${LIBTOOL} --mode=link --tag=CC ${CC} ${LDFLAGS} \
	    ${LIBS} -o libhttp_parser.la http_parser.lo \
	    -version-info 2:7:0 -rpath ${PREFIX}/lib

do-install:
	cd ${WRKSRC} && ${LIBTOOL} --mode=install ${INSTALL_LIB} \
	    -c libhttp_parser.la ${DESTDIR}${PREFIX}/lib/libhttp_parser.la
	${INSTALL_DATA} ${WRKSRC}/http_parser.h ${DESTDIR}${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
