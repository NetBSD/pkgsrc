# $NetBSD: Makefile,v 1.11 2006/01/24 07:32:42 wiz Exp $

DISTNAME=	mod_throttle312
PKGNAME=	ap-throttle-3.1.2
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://www.snert.com/Software/mod_throttle/
EXTRACT_SUFX=	.tgz

MAINTAINER=	eric@cirr.com
HOMEPAGE=	${MASTER_SITES}
COMMENT=	Apache module for limiting bandwidth usage

WRKSRC=         ${WRKDIR}/${PKGNAME_NOREV:S/ap-/mod_/}

APACHE_MODULE_NAME=	mod_throttle.so
APACHE_MODULE_SRC=	mod_throttle.c

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mod_throttle
	${INSTALL_DATA} ${WRKSRC}/index.shtml \
			${PREFIX}/share/doc/mod_throttle/index.html

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
