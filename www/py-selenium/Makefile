# $NetBSD: Makefile,v 1.16 2023/10/10 17:09:10 triaxx Exp $

DISTNAME=	selenium-4.14.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/selenium/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/SeleniumHQ/selenium
COMMENT=	Python bindings for Selenium
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-urllib3-[0-9]*:../../www/py-urllib3

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

# these are for Linux only; see selenium/webdriver/firefox/firefox_binary.py
CHECK_SHLIBS_SKIP+=	${PYSITELIB}/selenium/webdriver/firefox/amd64/x_ignore_nofocus.so
CHECK_SHLIBS_SKIP+=	${PYSITELIB}/selenium/webdriver/firefox/x86/x_ignore_nofocus.so
CHECK_SSP_SKIP=		${CHECK_SHLIBS_SKIP}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
