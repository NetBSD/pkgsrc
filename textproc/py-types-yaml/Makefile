# $NetBSD: Makefile,v 1.12 2025/03/05 10:33:24 wiz Exp $

DISTNAME=	types_pyyaml-6.0.12.20241230
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/:S/py//}
PKGREVISION=	1
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
