# $NetBSD: Makefile,v 1.6 2002/12/02 15:18:00 wiz Exp $

DISTNAME=	ZPhotoSlides-0.6
PKGNAME=	zope25-ZPhotoSlides-0.6
CATEGORIES=	www
MASTER_SITES=	http://www.zope.org/Members/p3b/ZPhotoSlides/
EXTRACT_SUFX=	.tar

DEPENDS+=	zope25-LocalFS-[0-9]*:../../www/zope25-LocalFS
BUILDLINK_DEPENDS.pyimaging= ${PYPKGPREFIX}-imaging>=1.1.3

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.zope.org/Members/p3b/ZPhotoSlides
COMMENT=	present your photos quickly in zope

ZOPE_COPYPRODUCT= zope-std-copyproduct-short
USE_BUILDLINK2=	yes

.include "../../www/zope25/product.mk"
.include "../../graphics/py-imaging/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
