# $NetBSD: Makefile,v 1.6 2003/06/10 20:30:36 jmc Exp $

DISTNAME=	mod_throttle312
PKGNAMENOREV=	ap-throttle-3.1.2
PKGNAME=	${PKGNAMENOREV}
PKGREVISION=	1
WRKSRC=         ${WRKDIR}/${PKGNAMENOREV:S/ap-/mod_/}
CATEGORIES=	www
MASTER_SITES=	http://www.snert.com/Software/mod_throttle/
EXTRACT_SUFX=	.tgz

MAINTAINER=	eric@cirr.com
HOMEPAGE=	${MASTER_SITES}
COMMENT=	Apache module for limiting bandwidth usage

USE_BUILDLINK2=	YES

APACHE_MODULE_NAME=	mod_throttle.so
APACHE_MODULE_SRC=	mod_throttle.c

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mod_throttle
	${INSTALL_DATA} ${WRKSRC}/index.shtml \
			${PREFIX}/share/doc/mod_throttle/index.html

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
