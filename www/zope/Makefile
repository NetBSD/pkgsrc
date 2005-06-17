# $NetBSD: Makefile,v 1.23 2005/06/17 03:50:43 jlam Exp $
#

DISTNAME=	Zope-2.2.2-src
PKGNAME=	zope-2.2.2
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=   http://www.zope.org/Products/Zope/2.2.2/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://www.zope.org/
COMMENT=	Zope, the Z Object Publishing Environment

DEPENDS+=	py-extclass>=2.2.2:../../lang/py-extclass
DEPENDS+=	py-dtml>=2.2.2:../../textproc/py-dtml

DIST_SUBDIR=	python

PLIST_SRC=	${WRKDIR}/.PLIST_SRC

ZOPEDIR=	${PREFIX}/lib/zope

PYTHON_VERSIONS_ACCEPTED= 20 # XXX for now

INSTALLATION_DIRS=	sbin

do-configure:
	${SED} -e "s,@PREFIX@,${PREFIX}," \
		<${FILESDIR}/Makefile.in > ${WRKSRC}/Makefile
	cd ${WRKSRC}/lib && ${RM} -rf Components/zlib \
		Components/ExtensionClass python/DocumentTemplate \
		python/StructuredText
	cd ${WRKSRC} && make configure

do-install:
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	${INSTALL_DATA_DIR} ${ZOPEDIR}
	cd ${WRKSRC} && ${PAX} -rw -s'/.*\.[cho]$$//' . ${ZOPEDIR}
	${PYTHONBIN} \
		${PREFIX}/lib/python2.0/compileall.py ${ZOPEDIR}
	${CHMOD} -R a+rX ${ZOPEDIR}
	cd ${PREFIX} && ${FIND} lib/zope \( -type f -o -type l \) -print >>${PLIST_SRC}
	cd ${PREFIX} && ${FIND} lib/zope -type d -print | ${SORT} -r | \
	${SED} -e "s/^/@dirrm /" >>${PLIST_SRC}
	${SED} -e "s,/usr/pkg,${PREFIX}," \
		<${FILESDIR}/zope-install.py >${PREFIX}/sbin/zope-install
	${SED} -e "s,/usr/pkg,${PREFIX}," \
		<${FILESDIR}/zope-shutdown.py >${PREFIX}/sbin/zope-shutdown
	${CHMOD} 755 ${PREFIX}/sbin/zope-install ${PREFIX}/sbin/zope-shutdown

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
