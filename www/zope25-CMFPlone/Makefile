# $NetBSD: Makefile,v 1.12 2005/09/28 12:37:53 rillig Exp $

DISTNAME=	CMFPlone1.0.3
PKGNAME=	zope25-CMFPlone-1.0.3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=/plone/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.plone.org/
COMMENT=	Content Management System

BUILDLINK_DEPENDS.zope=	zope-2.6.*
DEPENDS+=	zope25-CMF-[0-9]*:../../www/zope25-CMF
DEPENDS+=	zope25-Formulator-[0-9]*:../../www/zope25-Formulator

WRKSRC=		${WRKDIR}/CMFPlone-1.0.3

# no ActivePak with Zope 2.6.x!
PRODNAMES=	CMFPlone DCWorkflow

JUNKFILES=	.\#HISTORY.txt.1.88.2.78 .\#WorkflowTool.py.1.7.2.3 \
		.HISTORY.txt.swp migrations/.\#one02_one03.py.1.1.2.2 \
		skins/plone_templates/.\#main_template.pt.1.59.2.22

post-extract:
.for i in ${JUNKFILES}
	${RM} ${WRKSRC}/CMFPlone/${i}
.endfor

.include "../../www/zope25/product.mk"
.include "../../mk/bsd.pkg.mk"
