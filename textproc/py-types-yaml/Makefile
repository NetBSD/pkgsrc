# $NetBSD: Makefile,v 1.18 2026/04/14 12:34:59 adam Exp $

DISTNAME=	types_pyyaml-6.0.12.20260408
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/:S/py//}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/types-PyYAML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python/typeshed
COMMENT=	Typing stubs for PyYAML
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
