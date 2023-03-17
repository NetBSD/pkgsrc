# $NetBSD: Makefile,v 1.6 2023/03/17 13:52:55 adam Exp $

DISTNAME=	PyQt5_sip-12.11.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/PyQt5_sip/sip-qt5/}
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyQt5_sip/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.riverbankcomputing.com/software/sip/
COMMENT=	Qt5 support for sip
LICENSE=	sip-license OR gnu-gpl-v2 OR gnu-gpl-v3

USE_LANGUAGES=	c c++

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
