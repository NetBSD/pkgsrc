# $NetBSD: Makefile,v 1.5 2015/04/13 23:12:43 rodent Exp $

DISTNAME=	jsonlib-python3-1.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-python3//}
CATEGORIES=	textproc python
MASTER_SITES=	https://launchpad.net/jsonlib/python3/1.6.1/+download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/jsonlib
COMMENT=	JSON serializer/deserializer for Python (python-3.x version)
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
