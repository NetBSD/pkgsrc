# $NetBSD: Makefile,v 1.10 2025/07/05 11:44:16 wiz Exp $

DISTNAME=	lxml_html_clean-0.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lxml-html-clean/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fedora-python/lxml_html_clean
COMMENT=	HTML cleaner from lxml project
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml

PYTHON_VERSIONS_INCOMPATIBLE=	39 310

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
