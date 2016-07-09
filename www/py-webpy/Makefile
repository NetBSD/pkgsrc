# $NetBSD: Makefile,v 1.16 2016/07/09 13:04:15 wiz Exp $

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
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # not yet ported as of 0.37

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
