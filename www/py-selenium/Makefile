# $NetBSD: Makefile,v 1.17 2026/08/02 03:11:55 adam Exp $

DISTNAME=	selenium-4.46.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/selenium/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/SeleniumHQ/selenium
COMMENT=	Python bindings for Selenium
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-rust>=0:../../devel/py-setuptools-rust
DEPENDS+=	${PYPKGPREFIX}-certifi>=2026.2.25:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-trio>=0.31.0:../../devel/py-trio
DEPENDS+=	${PYPKGPREFIX}-trio-websocket>=0.12.2:../../www/py-trio-websocket
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.15.0:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-urllib3>=2.6.3:../../www/py-urllib3
DEPENDS+=	${PYPKGPREFIX}-websocket-client>=1.8.0:../../www/py-websocket-client

USE_TOOLS+=	pkg-config

.include "cargo-depends.mk"

.include "../../archivers/xz/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
