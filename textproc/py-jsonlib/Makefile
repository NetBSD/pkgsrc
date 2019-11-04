# $NetBSD: Makefile,v 1.15 2019/11/04 21:43:46 rillig Exp $

DISTNAME=	jsonlib-1.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jsonlib/}

MAINTAINER=	wenheping@gmail.com
HOMEPAGE=	https://launchpad.net/jsonlib
COMMENT=	JSON serializer/deserializer for Python (python-2.x version)
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c

PYTHON_VERSIONS_ACCEPTED=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
