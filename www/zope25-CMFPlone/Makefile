# $NetBSD: Makefile,v 1.4 2003/04/23 14:57:04 drochner Exp $

DISTNAME=	CMFPlone1.0.1
PKGNAME=	zope25-CMFPlone-1.0.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=/plone/}
WRKSRC=		${WRKDIR}/CMFPlone-1.0.1

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.plone.org/
COMMENT=	Content Management System

BUILDLINK_DEPENDS.zope=	zope-2.6.*
DEPENDS+=	zope25-CMF-[0-9]*:../../www/zope25-CMF
DEPENDS+=	zope25-Formulator-[0-9]*:../../www/zope25-Formulator

# no ActivePak with Zope 2.6.x!
PRODNAMES=	CMFPlone DCWorkflow
ZOPE_COPYPRODUCT= zope-std-copyproduct-short

.include "../../www/zope25/product.mk"
.include "../../mk/bsd.pkg.mk"
