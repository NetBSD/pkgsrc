# $NetBSD: Makefile,v 1.21 2006/03/04 21:31:06 jlam Exp $

DISTNAME=	ZPhotoSlides-1.1b
PKGNAME=	zope25-ZPhotoSlides-1.1b
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://www.zope.org/Members/p3b/ZPhotoSlides/

DEPENDS+=	zope25-LocalFS-[0-9]*:../../www/zope25-LocalFS
BUILDLINK_DEPENDS.pyimaging+=	${PYPKGPREFIX}-imaging>=1.1.3

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.zope.org/Members/p3b/ZPhotoSlides
COMMENT=	Present your photos quickly in zope

post-install:
	${FIND} ${PREFIX}/lib/zope/lib/python/Products/ZPhotoSlides -name CVS -type d -print | ${XARGS} ${RM} -r

.include "../../www/zope25/product.mk"
.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
