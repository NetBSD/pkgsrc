# $NetBSD: Makefile,v 1.24 2020/07/13 20:05:13 wiz Exp $

DISTNAME=	web.py-0.37
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	http://webpy.org/static/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://webpy.org/
COMMENT=	Simple, public domain web publishing system
LICENSE=	public-domain

USE_LANGUAGES=	#none

REPLACE_PYTHON+=		web/__init__.py web/utils.py
PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 0.37

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
