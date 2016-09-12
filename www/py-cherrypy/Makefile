# $NetBSD: Makefile,v 1.16 2016/09/12 17:44:14 adam Exp $

DISTNAME=	CherryPy-8.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=C/CherryPy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cherrypy.org/
COMMENT=	CherryPy is a pythonic, object-oriented HTTP framework
LICENSE=	modified-bsd

USE_LANGUAGES=		# none

REPLACE_PYTHON=		cherrypy/cherryd
REPLACE_PYTHON+=	cherrypy/test/sessiondemo.py

DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
