# $NetBSD: Makefile,v 1.10 2016/07/09 13:04:10 wiz Exp $

DISTNAME=	jsonlib-1.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jsonlib/}

MAINTAINER=	wenheping@gmail.com
HOMEPAGE=	https://launchpad.net/jsonlib
COMMENT=	JSON serializer/deserializer for Python (python-2.x version)
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c

PYTHON_VERSIONS_INCOMPATIBLE=	34 35

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
