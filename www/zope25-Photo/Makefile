# $NetBSD: Makefile,v 1.13 2006/04/17 13:46:52 wiz Exp $

DISTNAME=	Photo-1.2.3
PKGNAME=	zope25-Photo-1.2.3
PKGREVISION=	7
CATEGORIES=	www
MASTER_SITES=	http://www.zope.org/Members/rbickers/Photo/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.zope.org/Members/rbickers/Photo
COMMENT=	Photo object and Photo Folder object

ZOPE_COPYPRODUCT= zope-std-copyproduct-short

.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../www/zope25/product.mk"
.include "../../mk/bsd.pkg.mk"
