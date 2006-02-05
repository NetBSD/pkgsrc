# $NetBSD: Makefile,v 1.7 2006/02/05 23:11:30 joerg Exp $
#

DISTNAME=	RenderableCharts-0.6
PKGNAME=	zope25-RenderableCharts-0.6
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://www.zope.org/Members/Dirk.Datzert/RenderableCharts/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.zope.org/Members/Dirk.Datzert/RenderableCharts/
COMMENT=	Drawings with reportlab's graphics toolkit

DEPENDS+=	${PYPKGPREFIX}-reportlab>=1.17:../../print/py-reportlab
DEPENDS+=	${PYPKGPREFIX}-reportlab-renderPM-[0-9]*:../../print/py-reportlab-renderPM


.include "../../www/zope25/product.mk"
.include "../../mk/bsd.pkg.mk"
