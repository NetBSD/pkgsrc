# $NetBSD: Makefile,v 1.8 2025/03/03 07:07:11 wiz Exp $

DISTNAME=	pyqt6_sip-13.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pyqt6_sip/sip-qt6/}
PKGREVISION=	1
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyqt6_sip/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Python-SIP/sip
COMMENT=	Qt6 support for sip
LICENSE=	sip-license OR gnu-gpl-v2 OR gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=75.8.2:../../devel/py-setuptools

USE_LANGUAGES=	c c++

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
