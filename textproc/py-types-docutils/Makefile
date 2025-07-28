# $NetBSD: Makefile,v 1.1 2025/07/28 13:31:36 dkazankov Exp $

DISTNAME=	types_docutils-0.21.0.20250604
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/types-docutils/}

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/python/typeshed
COMMENT=	Typing stubs for docutils
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

.include "../../lang/python/wheel.mk"

.include "../../mk/bsd.pkg.mk"
