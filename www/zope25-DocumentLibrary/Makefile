# $NetBSD: Makefile,v 1.5 2003/07/17 22:56:10 grant Exp $

DISTNAME=	DocumentLibrary-1.0rc1
PKGREVISION=	1
PKGNAME=	zope25-DocumentLibrary-1.0rc1
CATEGORIES=	www
MASTER_SITES=	http://www.zope.org/Members/Kaivo/DocumentLibrary/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.zope.org/Members/Kaivo/DocumentLibrary
COMMENT=	searchable and browsable document libraries

DEPENDS+=	zope25-BTreeFolder-[0-9]*:../../www/zope25-BTreeFolder
ZOPE_COPYPRODUCT= zope-std-copyproduct-short

post-extract:
	${FIND} -d ${WRKSRC} -name CVS -type d -exec ${RM} -rf {} \;

.include "../../www/zope25/product.mk"
.include "../../mk/bsd.pkg.mk"
