# $NetBSD: Makefile,v 1.1.1.1 2002/11/14 16:50:38 drochner Exp $

DISTNAME=	CMFPlone1.0beta3
PKGNAME=	zope25-CMFPlone-1.0beta3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=/plone/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.plone.org/
COMMENT=	Content Management System

DEPENDS+=	zope25-CMF-*:../../www/zope25-CMF
DEPENDS+=	zope25-Formulator-*:../../www/zope25-Formulator

WRKSRC=		${WRKDIR}/CMFPlone-1.0beta3
PRODNAMES=	ActivePak CMFPlone DCWorkflow
ZOPE_COPYPRODUCT= zope-std-copyproduct-short

.include "../../www/zope25/product.mk"
.include "../../mk/bsd.pkg.mk"
