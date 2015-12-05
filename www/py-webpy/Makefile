# $NetBSD: Makefile,v 1.15 2015/12/05 21:26:07 adam Exp $

DISTNAME=	web.py-0.37
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	http://webpy.org/static/

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	http://webpy.org/
COMMENT=	Simple, public domain web publishing system
LICENSE=	public-domain

USE_LANGUAGES=	#none

REPLACE_PYTHON+=	web/__init__.py web/utils.py
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # not yet ported as of 0.37

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
