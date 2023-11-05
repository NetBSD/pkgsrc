# $NetBSD: Makefile,v 1.28 2023/11/05 10:54:16 wiz Exp $

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}

COMMENT=	Python WSGI Utility Library

PYTHON_VERSIONS_INCOMPATIBLE=	27

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core-[0-9]*:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-markupsafe>=2.1.1:../../textproc/py-markupsafe
# optional
#DEPENDS+=	${PYPKGPREFIX}-cryptography-[0-9]*:../../security/py-cryptography
#DEPENDS+=	${PYPKGPREFIX}-greenlet-[0-9]*:../../devel/py-greenlet
# optional, but required for tests
TEST_DEPENDS+=	${PYPKGPREFIX}-watchdog-[0-9]*:../../sysutils/py-watchdog
TEST_DEPENDS+=	${PYPKGPREFIX}-ephemeral_port_reserve-[0-9]*:../../net/py-ephemeral_port_reserve
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout-[0-9]*:../../devel/py-test-timeout
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xprocess-[0-9]*:../../devel/py-test-xprocess

EGDIR=			share/examples/${PKGBASE}
PLIST_SUBST+=		EGDIR=${EGDIR}
INSTALLATION_DIRS+=	${EGDIR}
PRINT_PLIST_AWK+=	{ gsub(/${EGDIR:S,/,\\/,g}/, "$${EGDIR}") }

USE_TOOLS+=	pax

post-install:
	${CHMOD} ${SHAREMODE} ${DESTDIR}${PREFIX}/${PYSITELIB}/werkzeug/debug/shared/*.png
	cd ${WRKSRC}/examples && ${PAX} -rwppm . ${DESTDIR}${PREFIX}/${EGDIR}
	${CHMOD} ${SHAREMODE} ${DESTDIR}${PREFIX}/${EGDIR}/*.py
	${CHMOD} ${SHAREMODE} ${DESTDIR}${PREFIX}/${EGDIR}/cupoftee/shared/*.png

.include "../../www/py-werkzeug/Makefile.common"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
