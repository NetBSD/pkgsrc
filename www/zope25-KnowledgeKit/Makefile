# $NetBSD: Makefile,v 1.2 2003/05/02 11:56:50 wiz Exp $
#

DISTNAME=	KnowledgeKit-1.6.7
PKGREVISION=	1
PKGNAME=	zope25-KnowledgeKit-1.6.7
CATEGORIES=	www
MASTER_SITES=	http://www.zope.org/Members/Bill/Products/KnowledgeKit/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.zope.org/Members/Bill/Products/KnowledgeKit/
COMMENT=	automatic creation and maintenance of Knowledge Bases

ZOPE_COPYPRODUCT= KnowledgeKit-copyimport
PRODNAMES=	#nothing

KnowledgeKit-copyimport:
	${CP} ${WRKSRC}/import/* ${ZOPEDIR}/import

.include "../../www/zope25/product.mk"
.include "../../mk/bsd.pkg.mk"
