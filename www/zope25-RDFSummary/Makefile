# $NetBSD: Makefile,v 1.7 2006/02/22 20:56:30 wiz Exp $
#

DISTNAME=	RDFSummary-2.3
PKGNAME=	zope25-RDFSummary-2.3
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.zope.org/Members/EIONET/RDFSummary/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.zope.org/Members/EIONET/RDFSummary
COMMENT=	Display content from other web sites via RSS

ZOPE_COPYPRODUCT= zope-std-copyproduct-short

# clean up after patch-aa
post-install:
	${RM} ${PREFIX}/lib/zope/lib/python/Products/RDFSummary/RDFSummary.py.orig

.include "../../www/zope25/product.mk"
.include "../../mk/bsd.pkg.mk"
