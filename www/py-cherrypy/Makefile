# $NetBSD: Makefile,v 1.2 2011/04/28 09:57:05 adam Exp $

DISTNAME=	CherryPy-3.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	http://download.cherrypy.org/cherrypy/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cherrypy.org/
COMMENT=	CherryPy is a pythonic, object-oriented HTTP framework
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# none
EGG_NAME=		${DISTNAME}

REPLACE_PYTHON=		py2/cherrypy/cherryd
REPLACE_PYTHON+=	py3/cherrypy/cherryd

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
