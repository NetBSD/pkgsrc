# $NetBSD: Makefile,v 1.1.1.1 2002/09/12 18:10:55 drochner Exp $

DISTNAME=	JPicture-2_0
PKGNAME=	zope25-JPicture-2.0
CATEGORIES=	www
MASTER_SITES=	http://www.dataflake.org/software/jpicture/
EXTRACT_SUFX=	.tgz

BUILDLINK_DEPENDS.pyimaging= ${PYPKGPREFIX}-imaging>=1.1.3

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.dataflake.org/software/jpicture/
COMMENT=	present your photos quickly in zope

ZOPE_COPYPRODUCT= zope-std-copyproduct-short

.include "../../www/zope25/product.mk"
.include "../../graphics/py-imaging/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
