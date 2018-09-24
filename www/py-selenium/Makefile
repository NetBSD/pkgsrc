# $NetBSD: Makefile,v 1.11 2018/09/24 09:32:30 adam Exp $

DISTNAME=	selenium-3.14.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/selenium/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/SeleniumHQ/selenium
COMMENT=	Python bindings for Selenium
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-urllib3-[0-9]*:../../www/py-urllib3

USE_LANGUAGES=	# none

# these are for Linux only; see selenium/webdriver/firefox/firefox_binary.py
CHECK_SHLIBS_SKIP+=	${PYSITELIB}/selenium/webdriver/firefox/amd64/x_ignore_nofocus.so
CHECK_SHLIBS_SKIP+=	${PYSITELIB}/selenium/webdriver/firefox/x86/x_ignore_nofocus.so

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
