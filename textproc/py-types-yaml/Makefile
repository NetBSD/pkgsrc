# $NetBSD: Makefile,v 1.21 2026/08/12 07:42:21 adam Exp $

DISTNAME=	types_pyyaml-6.0.12.20260724
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/:S/py//}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/types-PyYAML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python/typeshed
COMMENT=	Typing stubs for PyYAML
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=82.0.1:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
