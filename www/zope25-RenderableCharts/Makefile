# $NetBSD: Makefile,v 1.2 2003/12/24 09:53:50 jmmv Exp $
#

DISTNAME=	RenderableCharts-0.6
PKGNAME=	zope25-RenderableCharts-0.6
CATEGORIES=	www
MASTER_SITES=	http://www.zope.org/Members/Dirk.Datzert/RenderableCharts/

MAINTAINER=	packages@NetBSD.org
HOMEPAGE=	http://www.zope.org/Members/Dirk.Datzert/RenderableCharts/
COMMENT=	Drawings with reportlab's graphics toolkit

USE_BUILDLINK2=	yes
BUILDLINK_DEPENDS.pyreportlab= ${PYPKGPREFIX}-reportlab>=1.17

.include "../../www/zope25/product.mk"
.include "../../print/py-reportlab/buildlink2.mk"
.include "../../print/py-reportlab-renderPM/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
