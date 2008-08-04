# $NetBSD: Makefile,v 1.15 2008/08/04 09:28:31 obache Exp $

DISTNAME=	JPicture-2_0
PKGREVISION=	3
PKGNAME=	zope25-JPicture-2.0
CATEGORIES=	www
MASTER_SITES=	http://www.dataflake.org/old_stuff/jpicture/jpicture_2.0/${DISTNAME}${EXTRACT_SUFX}/download?file=/
EXTRACT_SUFX=	.tgz

BUILDLINK_API_DEPENDS.pyimaging+=	${PYPKGPREFIX}-imaging>=1.1.3

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.dataflake.org/old_stuff/jpicture/
COMMENT=	Present your photos quickly in zope

ZOPE_COPYPRODUCT= zope-std-copyproduct-short

.include "../../www/zope25/product.mk"
.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
