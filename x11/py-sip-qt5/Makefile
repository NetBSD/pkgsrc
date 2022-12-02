# $NetBSD: Makefile,v 1.3 2022/12/02 15:24:30 wiz Exp $

DISTNAME=	PyQt5_sip-12.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/PyQt5_sip/sip-qt5/}
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyQt5_sip/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/PyQt5_sip/
COMMENT=	Qt5 support for sip
LICENSE=	sip-license OR gnu-gpl-v2 OR gnu-gpl-v3

USE_LANGUAGES=	c c++

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
