# $NetBSD: Makefile,v 1.1.1.1 2002/09/04 14:55:49 drochner Exp $

DISTNAME=	CMF-1.3
PKGNAME=	zope25-CMF-1.3
CATEGORIES=	www
MASTER_SITES=	http://cmf.zope.org/download/CMF-1.3/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://cmf.zope.org/
COMMENT=	Content Management Framework for Zope

WRKSRC=		${WRKDIR}/CMF-1.3
PRODNAMES=	CMFCalendar CMFCore CMFDefault CMFTopic
ZOPE_COPYPRODUCT= zope-std-copyproduct-short

.include "../../www/zope25/product.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
