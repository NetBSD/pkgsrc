# $NetBSD: Makefile,v 1.2 2023/08/04 04:54:43 adam Exp $

DISTNAME=	PyQt6_sip-13.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/PyQt6_sip/sip-qt6/}
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyQt6_sip/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.riverbankcomputing.com/software/sip/
COMMENT=	Qt6 support for sip
LICENSE=	sip-license OR gnu-gpl-v2 OR gnu-gpl-v3

USE_LANGUAGES=	c c++

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
