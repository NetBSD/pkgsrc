# $NetBSD: Makefile,v 1.4 2003/03/29 12:42:48 jmmv Exp $

DISTNAME=	mod_throttle312
PKGNAME=	ap-throttle-3.1.2
WRKSRC=         ${WRKDIR}/${PKGNAME:S/ap-/mod_/}
CATEGORIES=	www
MASTER_SITES=	http://www.snert.com/Software/mod_throttle/
EXTRACT_SUFX=	.tgz

MAINTAINER=	eric@cirr.com
HOMEPAGE=	${MASTER_SITES}
COMMENT=	Apache module for limiting bandwidth usage

USE_BUILDLINK2=	YES

APACHE_MODULE_NAME=	mod_throttle.so
APACHE_MODULE_SRC=	mod_throttle.c

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
