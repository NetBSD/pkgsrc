# $NetBSD: Makefile,v 1.13 2025/04/14 12:57:26 adam Exp $

DISTNAME=	types_pyyaml-6.0.12.20250402
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/:S/py//}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/types-PyYAML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python/typeshed
COMMENT=	Typing stubs for PyYAML
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=75.8.2:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
