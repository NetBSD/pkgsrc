# $NetBSD: Makefile,v 1.7 2005/06/06 02:25:34 minskim Exp $

DISTNAME=	DocumentLibrary-1.0rc1
PKGREVISION=	1
PKGNAME=	zope25-DocumentLibrary-1.0rc1
CATEGORIES=	www
MASTER_SITES=	http://www.zope.org/Members/Kaivo/DocumentLibrary/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.zope.org/Members/Kaivo/DocumentLibrary
COMMENT=	Searchable and browsable document libraries

DEPENDS+=	zope25-BTreeFolder-[0-9]*:../../www/zope25-BTreeFolder
ZOPE_COPYPRODUCT= zope-std-copyproduct-short

post-extract:
	d=`${FIND} ${WRKSRC} -name CVS -type d`; ${RM} -rf $${d}

.include "../../www/zope25/product.mk"
.include "../../mk/bsd.pkg.mk"
