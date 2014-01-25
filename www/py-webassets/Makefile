# $NetBSD: Makefile,v 1.4 2014/01/25 10:30:29 wiz Exp $

DISTNAME=	webassets-0.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/w/webassets/

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://elsdoerfer.name/docs/webassets/
COMMENT=	Asset management for Python web development
LICENSE=	modified-bsd

USE_LANGUAGES=	# empty

REPLACE_PYTHON+=src/webassets/filter/rjsmin/rjsmin.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
