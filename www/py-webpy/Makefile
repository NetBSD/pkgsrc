# $NetBSD: Makefile,v 1.25 2022/01/10 20:54:11 wiz Exp $

DISTNAME=	web.py-0.37
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
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
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
