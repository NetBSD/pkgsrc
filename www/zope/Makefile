# $NetBSD: Makefile,v 1.9 1999/09/23 17:42:59 tsarna Exp $
#

DISTNAME=	Zope-2.0.1-src
PKGNAME=	zope-2.0.1
CATEGORIES=	www
MASTER_SITES=   http://www.zope.org/Products/Zope/2.0.1/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.zope.org/

DEPENDS+=	python-1.5.2:../../lang/python

PLIST_SRC=	${WRKDIR}/.PLIST_SRC

ZOPEDIR=	${PREFIX}/lib/zope

do-configure:
	${SED} -e "s,@PREFIX@,${PREFIX}," \
		<${FILESDIR}/Makefile.in > ${WRKSRC}/Makefile
	(cd ${WRKSRC}; ${RM} -rf lib/Components/zlib)
	(cd ${WRKSRC}; make configure)

do-install:
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	${MKDIR} ${ZOPEDIR}
	(cd ${WRKSRC}; pax -r -w -s'/.*\.[cho]$$//' . ${ZOPEDIR})
	${PREFIX}/bin/python \
		${PREFIX}/lib/python1.5/compileall.py ${ZOPEDIR}
	chmod -R a+rX ${ZOPEDIR}
	(cd ${PREFIX}; find lib/zope \( -type f -o -type l \) -print >>${PLIST_SRC})
	(cd ${PREFIX}; find -d lib/zope -type d -print | \
	${SED} -e "s/^/@dirrm /" >>${PLIST_SRC})
	${SED} -e "s,/usr/pkg,${PREFIX}," \
		<${FILESDIR}/zope-install.py >${PREFIX}/sbin/zope-install
	${SED} -e "s,/usr/pkg,${PREFIX}," \
		<${FILESDIR}/zope-shutdown.py >${PREFIX}/sbin/zope-shutdown
	chmod 755 ${PREFIX}/sbin/zope-install ${PREFIX}/sbin/zope-shutdown

.include "../../mk/bsd.pkg.mk"
