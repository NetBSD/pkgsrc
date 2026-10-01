# $NetBSD: Makefile,v 1.37 2026/10/01 11:24:56 adam Exp $

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}

COMMENT=	Python WSGI Utility Library

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-markupsafe>=2.1.1:../../textproc/py-markupsafe
# optional
#DEPENDS+=	${PYPKGPREFIX}-greenlet>=0:../../devel/py-greenlet
TEST_DEPENDS+=	${PYPKGPREFIX}-cryptography>=0:../../security/py-cryptography
TEST_DEPENDS+=	${PYPKGPREFIX}-watchdog>=0:../../sysutils/py-watchdog
TEST_DEPENDS+=	${PYPKGPREFIX}-ephemeral_port_reserve>=0:../../net/py-ephemeral_port_reserve
TEST_DEPENDS+=	${PYPKGPREFIX}-iniconfig>=0:../../devel/py-iniconfig
TEST_DEPENDS+=	${PYPKGPREFIX}-pluggy>=0:../../devel/py-pluggy
TEST_DEPENDS+=	${PYPKGPREFIX}-cparser>=0:../../devel/py-cparser
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout>=0:../../devel/py-test-timeout
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xprocess>=0:../../devel/py-test-xprocess

# as of 3.1.8
# 3 failed, 965 passed, 1 skipped, 1 warning

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
