# $NetBSD: Makefile,v 1.2 2003/05/02 11:56:54 wiz Exp $
#

DISTNAME=	ZNavigator-2.02
PKGREVISION=	1
PKGNAME=	zope25-ZNavigator-2.02
CATEGORIES=	www
MASTER_SITES=	http://www.zope.org/Members/jonas/ZNavigator/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.zope.org/Members/jonas/ZNavigator/
COMMENT=	creating navigation bars

ZOPE_COPYPRODUCT= zope-std-copyproduct-long

post-install:
	${CP} ${ZOPEDIR}/lib/python/Products/ZNavigator/demo/navigator_demo.zexp \
		${ZOPEDIR}/import
	${RM} -rf ${ZOPEDIR}/lib/python/Products/ZNavigator/demo

.include "../../www/zope25/product.mk"
.include "../../mk/bsd.pkg.mk"
