# $NetBSD: Makefile,v 1.12 2006/03/04 21:31:05 jlam Exp $

DISTNAME=	JPicture-2_0
PKGREVISION=	3
PKGNAME=	zope25-JPicture-2.0
CATEGORIES=	www
MASTER_SITES=	http://www.dataflake.org/software/jpicture/
EXTRACT_SUFX=	.tgz

BUILDLINK_DEPENDS.pyimaging+=	${PYPKGPREFIX}-imaging>=1.1.3

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.dataflake.org/software/jpicture/
COMMENT=	Present your photos quickly in zope

ZOPE_COPYPRODUCT= zope-std-copyproduct-short

.include "../../www/zope25/product.mk"
.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
