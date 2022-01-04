# $NetBSD: Makefile,v 1.5 2022/01/04 20:54:52 wiz Exp $

DISTNAME=	antlr4-python3-runtime-4.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-python3-runtime//1}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/antlr4-python3-runtime/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://www.antlr.org/
COMMENT=	AntLR 4 bindings for Python
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
