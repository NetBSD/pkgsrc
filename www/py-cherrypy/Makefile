# $NetBSD: Makefile,v 1.13 2014/12/31 13:57:30 wiz Exp $

DISTNAME=	CherryPy-3.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/C/CherryPy/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cherrypy.org/
COMMENT=	CherryPy is a pythonic, object-oriented HTTP framework
LICENSE=	modified-bsd

USE_LANGUAGES=		# none

REPLACE_PYTHON=		cherrypy/cherryd
REPLACE_PYTHON+=	cherrypy/test/sessiondemo.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
