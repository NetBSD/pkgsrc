# $NetBSD: Makefile,v 1.16 2004/10/03 00:18:27 tv Exp $

DISTNAME=	ZPhotoSlides-1.1b
PKGNAME=	zope25-ZPhotoSlides-1.1b
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.zope.org/Members/p3b/ZPhotoSlides/

DEPENDS+=	zope25-LocalFS-[0-9]*:../../www/zope25-LocalFS
BUILDLINK_DEPENDS.pyimaging= ${PYPKGPREFIX}-imaging>=1.1.3

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.zope.org/Members/p3b/ZPhotoSlides
COMMENT=	Present your photos quickly in zope

USE_BUILDLINK3=	yes

.include "../../www/zope25/product.mk"
.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
