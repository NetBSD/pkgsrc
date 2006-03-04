# $NetBSD: Makefile,v 1.7 2006/03/04 21:31:05 jlam Exp $
#

DISTNAME=	KnowledgeKit-1.6.7
PKGNAME=	zope25-KnowledgeKit-1.6.7
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.zope.org/Members/Bill/Products/KnowledgeKit/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.zope.org/Members/Bill/Products/KnowledgeKit/
COMMENT=	Automatic creation and maintenance of Knowledge Bases

ZOPE_COPYPRODUCT= KnowledgeKit-copyimport
PRODNAMES=	#nothing

KnowledgeKit-copyimport:
	${CP} ${WRKSRC}/import/* ${ZOPEDIR}/import

.include "../../www/zope25/product.mk"
.include "../../mk/bsd.pkg.mk"
