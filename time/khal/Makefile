# $NetBSD: Makefile,v 1.43 2023/11/07 22:38:08 wiz Exp $

DISTNAME=	khal-0.11.2
PKGREVISION=	2
CATEGORIES=	time net python
MASTER_SITES=	${MASTER_SITE_PYPI:=k/khal/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/geier/khal
COMMENT=	CLI calendar application built around CalDAV
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-atomicwrites>=0.1.7:../../devel/py-atomicwrites
DEPENDS+=	${PYPKGPREFIX}-click>=3.2:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-click-log>=0.2.0:../../devel/py-click-log
DEPENDS+=	${PYPKGPREFIX}-configobj-[0-9]*:../../devel/py-configobj
DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-icalendar>=4.0.3:../../time/py-icalendar
DEPENDS+=	${PYPKGPREFIX}-pytz>=2018.7:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-tzlocal>=1.0:../../time/py-tzlocal
DEPENDS+=	${PYPKGPREFIX}-urwid>=1.3.0:../../devel/py-urwid
DEPENDS+=	${PYPKGPREFIX}-xdg>=0.17:../../devel/py-xdg
# not needed, but recommended, so let's just depend on it
DEPENDS+=	${PYPKGPREFIX}-setproctitle-[0-9]*:../../sysutils/py-setproctitle
# for the man page
TOOL_DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
TOOL_DEPENDS+=	${PYPKGPREFIX}-sphinxcontrib-newsfeed-[0-9]*:../../textproc/py-sphinxcontrib-newsfeed
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun-[0-9]*:../../devel/py-freezegun
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-vdirsyncer-[0-9]*:../../time/py-vdirsyncer

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

USE_PKG_RESOURCES=	yes

INSTALLATION_DIRS=	share/doc/khal ${PKGMANDIR}/man1
REPLACE_PYTHON+=	khal/*/*.py
REPLACE_PYTHON+=	khal/*.py

post-build:
	cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV} PYTHONPATH=${WRKSRC} \
		sphinx-build-${PYVERSSUFFIX} -b man -d build/doctrees source build/man

post-install:
	${INSTALL_DATA} ${WRKSRC}/khal.conf.sample ${DESTDIR}${PREFIX}/share/doc/khal
	${INSTALL_MAN} ${WRKSRC}/doc/build/man/khal.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

# as of 0.11.1
# 27 failed, 282 passed, 1 xfailed, 2 xpassed, 6 warnings
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
