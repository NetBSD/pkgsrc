# $NetBSD: Makefile,v 1.7 2012/10/28 06:30:59 asau Exp $

DISTNAME=	CherryPy-3.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	http://download.cherrypy.org/cherrypy/${PKGVERSION_NOREV}/

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
