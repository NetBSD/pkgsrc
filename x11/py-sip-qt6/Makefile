# $NetBSD: Makefile,v 1.6 2024/12/27 09:11:17 wiz Exp $

DISTNAME=	pyqt6_sip-13.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pyqt6_sip/sip-qt6/}
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyqt6_sip/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Python-SIP/sip
COMMENT=	Qt6 support for sip
LICENSE=	sip-license OR gnu-gpl-v2 OR gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=30.3:../../devel/py-setuptools

USE_LANGUAGES=	c c++

WHEEL_NAME=	${DISTNAME:S/pyqt6/PyQt6/}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
