# $NetBSD: Makefile,v 1.3 2003/03/29 12:42:56 jmmv Exp $

DISTNAME=	CMFPlone1.0beta3
PKGNAME=	zope25-CMFPlone-1.0beta3
WRKSRC=		${WRKDIR}/CMFPlone-1.0beta3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=/plone/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.plone.org/
COMMENT=	Content Management System

DEPENDS+=	zope25-CMF-[0-9]*:../../www/zope25-CMF
DEPENDS+=	zope25-Formulator-[0-9]*:../../www/zope25-Formulator

PRODNAMES=	ActivePak CMFPlone DCWorkflow
ZOPE_COPYPRODUCT= zope-std-copyproduct-short

.include "../../www/zope25/product.mk"
.include "../../mk/bsd.pkg.mk"
