# $NetBSD: Makefile,v 1.4 2003/06/02 01:15:54 jschauma Exp $

DISTNAME=	JPicture-2_0
PKGREVISION=	1
PKGNAME=	zope25-JPicture-2.0
CATEGORIES=	www
MASTER_SITES=	http://www.dataflake.org/software/jpicture/
EXTRACT_SUFX=	.tgz

BUILDLINK_DEPENDS.pyimaging= ${PYPKGPREFIX}-imaging>=1.1.3

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.dataflake.org/software/jpicture/
COMMENT=	present your photos quickly in zope

ZOPE_COPYPRODUCT= zope-std-copyproduct-short
USE_BUILDLINK2=	yes

.include "../../www/zope25/product.mk"
.include "../../graphics/py-imaging/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
