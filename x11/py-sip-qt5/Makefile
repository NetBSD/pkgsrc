# $NetBSD: Makefile,v 1.20 2026/01/19 08:37:34 adam Exp $

DISTNAME=	pyqt5_sip-12.18.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pyqt5_sip/sip-qt5/}
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyQt5-sip/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Python-SIP/sip
COMMENT=	Qt5 support for sip
LICENSE=	sip-license OR gnu-gpl-v2 OR gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	c c++

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
