# $NetBSD: Makefile,v 1.8 2004/10/03 00:18:27 tv Exp $

DISTNAME=	Photo-1.2.3
PKGNAME=	zope25-Photo-1.2.3
PKGREVISION=	4
CATEGORIES=	www
MASTER_SITES=	http://www.zope.org/Members/rbickers/Photo/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.zope.org/Members/rbickers/Photo
COMMENT=	Photo object and Photo Folder object

ZOPE_COPYPRODUCT= zope-std-copyproduct-short
USE_BUILDLINK3=		yes

.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../www/zope25/product.mk"
.include "../../mk/bsd.pkg.mk"
