# $NetBSD: Makefile,v 1.16 2022/01/04 20:54:57 wiz Exp $

DISTNAME=	jsonlib-1.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
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
