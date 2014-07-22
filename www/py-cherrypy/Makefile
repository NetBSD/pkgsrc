# $NetBSD: Makefile,v 1.11 2014/07/22 09:52:54 wiz Exp $

DISTNAME=	CherryPy-3.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/C/CherryPy/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cherrypy.org/
COMMENT=	CherryPy is a pythonic, object-oriented HTTP framework
LICENSE=	modified-bsd

USE_LANGUAGES=		# none
EGG_NAME=		${DISTNAME}

REPLACE_PYTHON=		cherrypy/cherryd
REPLACE_PYTHON+=	cherrypy/test/sessiondemo.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
