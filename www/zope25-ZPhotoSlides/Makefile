# $NetBSD: Makefile,v 1.1.1.1 2002/09/04 15:01:49 drochner Exp $

DISTNAME=	ZPhotoSlides-0.3
PKGNAME=	zope25-ZPhotoSlides-0.3
CATEGORIES=	www
MASTER_SITES=	http://www.zope.org/Members/p3b/ZPhotoSlides/
EXTRACT_SUFX=	.tar

DEPENDS+=	zope25-LocalFS-*:../../www/zope25-LocalFS
BUILDLINK_DEPENDS.pyimaging= ${PYPKGPREFIX}-imaging>=1.1.3

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.zope.org/Members/p3b/ZPhotoSlides
COMMENT=	present your photos quickly in zope

ZOPE_COPYPRODUCT= zope-std-copyproduct-short

.include "../../www/zope25/product.buildlink.mk"
.include "../../graphics/py-imaging/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
