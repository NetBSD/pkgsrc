# $NetBSD: Makefile,v 1.12 2012/02/02 09:57:27 hans Exp $
# FreeBSD Id: ports/www/zope29/Makefile,v 1.86 2006/08/03 15:53:04 garga Exp

DISTNAME=	Zope-${ZOPE210_VERSION}-final
PKGNAME=	${ZOPE_PKG_PREFIX}-${ZOPE210_VERSION}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://www.zope.org/Products/Zope/${ZOPE210_VERSION}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.zope.org/
COMMENT=	Zope ${ZOPE210_VERSION}, the Z Object Publishing Environment

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PYPKGPREFIX}-expat>=0:../../textproc/py-expat

PYTHON_VERSIONS_ACCEPTED=	24
ZOPE_VERSION=			210

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${ZOPE_DIR} --with-python=${PYTHONBIN}
BUILD_TARGET=	build version_txt
MAKE_FILE=	makefile

.include "../../mk/bsd.prefs.mk"

.if ${_USE_DESTDIR} != "no"
INSTALL_MAKE_FLAGS=	INSTALL_FLAGS=--root=${DESTDIR:Q}
.endif

INSTALLATION_DIRS=	${ZOPE_DOC_DIR}/zeo ${ZOPE_DOC_DIR}/zope
OWN_DIRS+=		${ZOPE_PRODUCTS_DIR}
RCD_SCRIPTS=		zope${ZOPE_VERSION} zeo${ZOPE_VERSION}
RCD_SCRIPT_SRC.zope${ZOPE_VERSION}=	../zope/files/zope.sh
RCD_SCRIPT_SRC.zeo${ZOPE_VERSION}=	../zope/files/zeo.sh

OWN_DIRS+= ${ZOPE_BASE}/skel/etc/package-includes ${ZOPE_PRODUCTS_BASE}

SUBST_CLASSES+=		param
SUBST_STAGE.param=	pre-configure
SUBST_FILES.param+=	skel/etc/zope.conf.in utilities/mkzopeinstance.py
SUBST_SED.param+=  -e "s|@ZOPE_PRODUCTS_DIR@|${ZOPE_PRODUCTS_DIR}|g"
SUBST_SED.param+=	-e "s|@ZOPE_USER@|${ZOPE_USER}|g"
SUBST_SED.param+=	-e "s|@ZOPE_GROUP@|${ZOPE_GROUP}|g"
SUBST_MESSAGE.param=	Fixing some parameters in files.

REPLACE_PYTHON=	\
	lib/python/AccessControl/securitySuite/regressionSecurity.py \
	lib/python/Interface/pyskel.py lib/python/OFS/ndiff.py \
	lib/python/Products/PageTemplates/tests/run.py \
	lib/python/Products/PluginIndexes/TextIndex/Splitter/setup.py \
	lib/python/StructuredText/ClassicStructuredText.py \
	lib/python/ZConfig/tests/runtests.py lib/python/ZEO/zeoctl.py \
	lib/python/Zope2/Startup/zopectl.py lib/python/ZTUtils/tests/run.py \
	lib/python/Zope2/Startup/misc/zpasswd.py \
	lib/python/docutils/readers/python/pynodes.py \
	lib/python/pytz/tzfile.py lib/python/zdaemon/tests/nokill.py \
	lib/python/zdaemon/zdctl.py lib/python/zdaemon/zdrun.py \
	lib/python/zope/security/setup.py test.py
REPLACE_PYTHON_DIRS+=	lib/python/Products/ZCTextIndex/tests \
	lib/python/Products/ZCatalog/regressiontests \
	lib/python/Products/ZGadflyDA/gadfly lib/python/TAL \
	lib/python/ZConfig/scripts lib/python/ZEO/scripts \
	lib/python/ZODB/scripts lib/python/ZServer/medusa \
	lib/python/zope/app/locales lib/python/zope/index/text/tests \
	lib/python/zope/rdb/gadfly lib/python/zope/tal utilities

USE_TOOLS+=	pax

post-extract:
	cd ${WRKSRC}; ${FIND} doc lib skel/import -type f -print | \
		${XARGS} ${CHMOD} -x

pre-patch:
	${CP} ../zope/files/sitecustomize.py ${WRKSRC}/lib/python
	${RM} -f ${WRKSRC}/skel/bin/runzope.bat.in

post-build:
	cd ${WRKSRC}; ${PY_COMPILE_ALL} .

pre-install:
	${FIND} ${WRKSRC} \( -name '*.orig' -o -name svn-commit.tmp \) \
		-print | ${XARGS} -- ${RM} -f

post-install:
	cd ${WRKSRC}/doc/ZEO; pax -rw *.txt ${DESTDIR}${ZOPE_DOC_DIR}/zeo
	cd ${WRKSRC}/doc; pax -rw *.txt ${DESTDIR}${ZOPE_DOC_DIR}/zope
	${FIND} ${DESTDIR}${ZOPE_DIR} ${DESTDIR}${ZOPE_DOC_DIR} -type f -print \
		| ${XARGS} -- ${CHMOD} a-w+r
	${FIND} ${DESTDIR}${ZOPE_DIR} -type f -name '*.pyc' -print | \
		${XARGS} -- ${CHMOD} a-x

.include "../../www/zope/Makefile.common"
.include "../../www/zope/replace.mk"
.include "../../www/zope/zopeversion.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
