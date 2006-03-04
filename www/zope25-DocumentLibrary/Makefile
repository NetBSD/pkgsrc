# $NetBSD: Makefile,v 1.8 2006/03/04 21:31:05 jlam Exp $

DISTNAME=	DocumentLibrary-1.0rc1
PKGREVISION=	1
PKGNAME=	zope25-DocumentLibrary-1.0rc1
CATEGORIES=	www
MASTER_SITES=	http://www.zope.org/Members/Kaivo/DocumentLibrary/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.zope.org/Members/Kaivo/DocumentLibrary
COMMENT=	Searchable and browsable document libraries

DEPENDS+=	zope25-BTreeFolder-[0-9]*:../../www/zope25-BTreeFolder
ZOPE_COPYPRODUCT= zope-std-copyproduct-short

post-extract:
	d=`${FIND} ${WRKSRC} -name CVS -type d`; ${RM} -rf $${d}

.include "../../www/zope25/product.mk"
.include "../../mk/bsd.pkg.mk"
