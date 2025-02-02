# $NetBSD: Makefile,v 1.14 2025/02/02 10:38:04 he Exp $

DISTNAME=	pyqt5_sip-12.16.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pyqt5_sip/sip-qt5/}
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyQt5-sip/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.riverbankcomputing.com/software/sip/
COMMENT=	Qt5 support for sip
LICENSE=	sip-license OR gnu-gpl-v2 OR gnu-gpl-v3

WHEEL_NAME=	${DISTNAME:S/pyqt/PyQt/}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=69.5:../../devel/py-setuptools

USE_LANGUAGES=	c c++

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
