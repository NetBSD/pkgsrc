# $NetBSD: Makefile,v 1.5 2003/07/17 22:56:12 grant Exp $
#

DISTNAME=	KnowledgeKit-1.6.7
PKGNAME=	zope25-KnowledgeKit-1.6.7
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.zope.org/Members/Bill/Products/KnowledgeKit/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.zope.org/Members/Bill/Products/KnowledgeKit/
COMMENT=	automatic creation and maintenance of Knowledge Bases

ZOPE_COPYPRODUCT= KnowledgeKit-copyimport
PRODNAMES=	#nothing

KnowledgeKit-copyimport:
	${CP} ${WRKSRC}/import/* ${ZOPEDIR}/import

.include "../../www/zope25/product.mk"
.include "../../mk/bsd.pkg.mk"
