# $NetBSD: Makefile,v 1.3 2024/08/29 12:25:11 adam Exp $

DISTNAME=	lxml_html_clean-0.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lxml-html-clean/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fedora-python/lxml_html_clean
COMMENT=	HTML cleaner from lxml project
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=61.0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
