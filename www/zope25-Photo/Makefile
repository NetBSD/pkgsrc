# $NetBSD: Makefile,v 1.4 2003/07/17 22:56:14 grant Exp $

DISTNAME=	Photo-1.2.3
PKGREVISION=	1
PKGNAME=	zope25-Photo-1.2.3
CATEGORIES=	www
MASTER_SITES=	http://www.zope.org/Members/rbickers/Photo/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.zope.org/Members/rbickers/Photo
COMMENT=	Photo object and Photo Folder object

ZOPE_COPYPRODUCT= zope-std-copyproduct-short
USE_BUILDLINK2=	yes

.include "../../www/zope25/product.mk"
.include "../../graphics/py-imaging/buildlink2.mk"
.include "../../graphics/ImageMagick/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
