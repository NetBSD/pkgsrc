# $NetBSD: Makefile,v 1.8 2016/06/08 17:43:46 wiz Exp $

DISTNAME=	webassets-0.11.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/webassets/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://elsdoerfer.name/docs/webassets/
COMMENT=	Asset management for Python web development
LICENSE=	modified-bsd

USE_LANGUAGES=	# empty

REPLACE_PYTHON+=src/webassets/filter/rjsmin/rjsmin.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
