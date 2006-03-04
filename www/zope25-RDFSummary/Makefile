# $NetBSD: Makefile,v 1.8 2006/03/04 21:31:05 jlam Exp $
#

DISTNAME=	RDFSummary-2.3
PKGNAME=	zope25-RDFSummary-2.3
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.zope.org/Members/EIONET/RDFSummary/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.zope.org/Members/EIONET/RDFSummary
COMMENT=	Display content from other web sites via RSS

ZOPE_COPYPRODUCT= zope-std-copyproduct-short

# clean up after patch-aa
post-install:
	${RM} ${PREFIX}/lib/zope/lib/python/Products/RDFSummary/RDFSummary.py.orig

.include "../../www/zope25/product.mk"
.include "../../mk/bsd.pkg.mk"
