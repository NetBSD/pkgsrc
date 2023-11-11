# $NetBSD: Makefile,v 1.3 2023/11/11 18:31:52 nros Exp $

DISTNAME=	PyQt6_sip-13.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/PyQt6_sip/sip-qt6/}
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyQt6_sip/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.riverbankcomputing.com/software/sip/
COMMENT=	Qt6 support for sip
LICENSE=	sip-license OR gnu-gpl-v2 OR gnu-gpl-v3

USE_LANGUAGES=	c c++

PYTHON_VERSIONS_INCOMPATIBLE=	27

TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=30.3:../../devel/py-setuptools


.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
