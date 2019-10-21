# $NetBSD: Makefile,v 1.29 2019/10/21 22:15:10 adam Exp $

DISTNAME=		khal-0.10.1
PKGREVISION=		1
CATEGORIES=		time net
MASTER_SITES=		${MASTER_SITE_PYPI:=k/khal/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/geier/khal
COMMENT=		CLI calendar application built around CalDAV
LICENSE=		mit

DEPENDS+=		${PYPKGPREFIX}-atomicwrites-[0-9]*:../../devel/py-atomicwrites
DEPENDS+=		${PYPKGPREFIX}-click>=3.2:../../devel/py-click
DEPENDS+=		${PYPKGPREFIX}-click-log-[0-9]*:../../devel/py-click-log
DEPENDS+=		${PYPKGPREFIX}-configobj-[0-9]*:../../devel/py-configobj
DEPENDS+=		${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=		${PYPKGPREFIX}-icalendar>=3.9.2:../../time/py-icalendar
DEPENDS+=		${PYPKGPREFIX}-pkginfo-[0-9]*:../../devel/py-pkginfo
BUILD_DEPENDS+=		${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=		${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=		${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=		${PYPKGPREFIX}-tzlocal-[0-9]*:../../time/py-tzlocal
DEPENDS+=		${PYPKGPREFIX}-urwid>=1.1.0:../../devel/py-urwid
DEPENDS+=		${PYPKGPREFIX}-vdirsyncer>=0.5.2:../../time/py-vdirsyncer
DEPENDS+=		${PYPKGPREFIX}-xdg>=0.17:../../devel/py-xdg
# not needed, but recommended, so let's just depend on it
DEPENDS+=		${PYPKGPREFIX}-setproctitle-[0-9]*:../../sysutils/py-setproctitle
# for the man page
USE_TOOLS+=		gmake
BUILD_DEPENDS+=		${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
BUILD_DEPENDS+=		${PYPKGPREFIX}-sphinxcontrib-newsfeed-[0-9]*:../../textproc/py-sphinxcontrib-newsfeed
# 0.9.10: one test failure https://github.com/pimutils/khal/issues/825
# TEST_DEPENDS
BUILD_DEPENDS+=		${PYPKGPREFIX}-freezegun-[0-9]*:../../devel/py-freezegun
BUILD_DEPENDS+=		${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

PYTHON_VERSIONS_INCOMPATIBLE=	27 # not supported as of 0.8.0

INSTALLATION_DIRS=	share/doc/khal ${PKGMANDIR}/man1
REPLACE_PYTHON+=	khal/*/*.py
REPLACE_PYTHON+=	khal/*.py

post-build:
	cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV} PYTHONPATH=${WRKSRC} ${GMAKE} man SPHINXBUILD=sphinx-build-${PYVERSSUFFIX}

post-install:
	${INSTALL_DATA} ${WRKSRC}/khal.conf.sample ${DESTDIR}${PREFIX}/share/doc/khal
	${INSTALL_MAN} ${WRKSRC}/doc/build/man/khal.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

do-test:
	cd ${WRKSRC} && py.test-${PYVERSSUFFIX} tests

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
