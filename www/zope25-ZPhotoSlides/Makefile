# $NetBSD: Makefile,v 1.18 2005/12/05 20:51:15 rillig Exp $

DISTNAME=	ZPhotoSlides-1.1b
PKGNAME=	zope25-ZPhotoSlides-1.1b
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.zope.org/Members/p3b/ZPhotoSlides/

DEPENDS+=	zope25-LocalFS-[0-9]*:../../www/zope25-LocalFS
BUILDLINK_DEPENDS.pyimaging+=	${PYPKGPREFIX}-imaging>=1.1.3

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.zope.org/Members/p3b/ZPhotoSlides
COMMENT=	Present your photos quickly in zope


.include "../../www/zope25/product.mk"
.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
