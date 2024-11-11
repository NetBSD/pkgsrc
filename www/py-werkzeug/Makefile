# $NetBSD: Makefile,v 1.31 2024/11/11 09:19:57 wiz Exp $

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}

COMMENT=	Python WSGI Utility Library

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

# as of 3.1.0 - tests hang. interrupt gives:
# 1 failed, 693 passed
# https://github.com/pallets/werkzeug/issues/3002
pre-test:
	${RM} -f ${WRKSRC}/tests/test_serving.py
# with this file removed
# 1 failed, 919 passed
# before 3.1.0:
# 18 failed, 887 passed, 1 skipped

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
