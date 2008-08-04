# $NetBSD: Makefile,v 1.8 2008/08/04 09:28:31 obache Exp $
#

DISTNAME=	KnowledgeKit-1.6.7
PKGNAME=	zope25-KnowledgeKit-1.6.7
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.zope.org/Members/Bill/Products/KnowledgeKit/${PKGVERSION_NOREV}/
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
