# $NetBSD: Makefile,v 1.7 2003/06/12 16:40:00 drochner Exp $

DISTNAME=	CMFPlone1.0.2
PKGNAME=	zope25-CMFPlone-1.0.2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=/plone/}
WRKSRC=		${WRKDIR}/CMFPlone-1.0.2

MAINTAINER=	tech-pkg@netbsd.org
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
