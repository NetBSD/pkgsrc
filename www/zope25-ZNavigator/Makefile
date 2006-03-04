# $NetBSD: Makefile,v 1.7 2006/03/04 21:31:06 jlam Exp $
#

DISTNAME=	ZNavigator-2.02
PKGNAME=	zope25-ZNavigator-2.02
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.zope.org/Members/jonas/ZNavigator/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.zope.org/Members/jonas/ZNavigator/
COMMENT=	Creating navigation bars

ZOPE_COPYPRODUCT= zope-std-copyproduct-long

post-install:
	${CP} ${ZOPEDIR}/lib/python/Products/ZNavigator/demo/navigator_demo.zexp \
		${ZOPEDIR}/import
	${RM} -rf ${ZOPEDIR}/lib/python/Products/ZNavigator/demo

.include "../../www/zope25/product.mk"
.include "../../mk/bsd.pkg.mk"
