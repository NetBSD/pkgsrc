# $NetBSD: Makefile,v 1.10 2024/12/26 14:35:56 wiz Exp $

DISTNAME=	types_pyyaml-6.0.12.20241221
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/:S/py//}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/types-PyYAML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python/typeshed
COMMENT=	Typing stubs for PyYAML
LICENSE=	apache-2.0

WHEEL_NAME=	${DISTNAME:S/pyyaml/PyYAML/}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
