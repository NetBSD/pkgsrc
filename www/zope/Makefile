# $NetBSD: Makefile,v 1.12 2000/08/23 13:41:31 dmcmahill Exp $
#

DISTNAME=	Zope-2.1.4-src
PKGNAME=	zope-2.1.4
CATEGORIES=	www
MASTER_SITES=   http://www.zope.org/Products/Zope/2.1.4/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.zope.org/

DEPENDS+=	python-1.5.2:../../lang/python
DEPENDS+=	py-extclass-2.1.4:../../lang/py-extclass
DEPENDS+=	py-dtml-2.2.0:../../textproc/py-dtml

PLIST_SRC=	${WRKDIR}/.PLIST_SRC

ZOPEDIR=	${PREFIX}/lib/zope

do-configure:
	${SED} -e "s,@PREFIX@,${PREFIX}," \
		<${FILESDIR}/Makefile.in > ${WRKSRC}/Makefile
	(cd ${WRKSRC}/lib; ${RM} -rf Components/zlib \
		Components/ExtensionClass python/DocumentTemplate \
		python/StructuredText)
	(cd ${WRKSRC}; make configure)

do-install:
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	${MKDIR} ${ZOPEDIR}
	(cd ${WRKSRC}; ${PAX} -r -w -s'/.*\.[cho]$$//' . ${ZOPEDIR})
	${PREFIX}/bin/python \
		${PREFIX}/lib/python1.5/compileall.py ${ZOPEDIR}
	${CHMOD} -R a+rX ${ZOPEDIR}
	(cd ${PREFIX}; ${FIND} lib/zope \( -type f -o -type l \) -print >>${PLIST_SRC})
	(cd ${PREFIX}; ${FIND} -d lib/zope -type d -print | \
	${SED} -e "s/^/@dirrm /" >>${PLIST_SRC})
	${SED} -e "s,/usr/pkg,${PREFIX}," \
		<${FILESDIR}/zope-install.py >${PREFIX}/sbin/zope-install
	${SED} -e "s,/usr/pkg,${PREFIX}," \
		<${FILESDIR}/zope-shutdown.py >${PREFIX}/sbin/zope-shutdown
	${CHMOD} 755 ${PREFIX}/sbin/zope-install ${PREFIX}/sbin/zope-shutdown

.include "../../mk/bsd.pkg.mk"
