# $NetBSD: Makefile,v 1.8 2004/10/03 00:18:27 tv Exp $

DISTNAME=	JPicture-2_0
PKGREVISION=	2
PKGNAME=	zope25-JPicture-2.0
CATEGORIES=	www
MASTER_SITES=	http://www.dataflake.org/software/jpicture/
EXTRACT_SUFX=	.tgz

BUILDLINK_DEPENDS.pyimaging= ${PYPKGPREFIX}-imaging>=1.1.3

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.dataflake.org/software/jpicture/
COMMENT=	Present your photos quickly in zope

ZOPE_COPYPRODUCT= zope-std-copyproduct-short
USE_BUILDLINK3=	yes

.include "../../www/zope25/product.mk"
.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
