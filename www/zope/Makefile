# $NetBSD: Makefile,v 1.2 1998/12/18 00:39:02 tsarna Exp $
#

DISTNAME=	Zope-1.9.0b3-src
PKGNAME=	zope-1.9.0b3
CATEGORIES=	www
MASTER_SITES=   http://www.zope.org/Download/Releases/Zope-1.9.0b3/

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.zope.org/

DEPENDS+=	python-1.5.1:../../lang/python

CONFLICTS=	zope-1.9b1 zope-1.9.0b2

PLIST_SRC=	${WRKDIR}/.PLIST_SRC

ZOPEDIR=	${PREFIX}/zope

do-configure:
	${SED} -e "s,@PREFIX@,${PREFIX}," \
		<${FILESDIR}/Makefile.in > ${WRKSRC}/Makefile
	(cd ${WRKSRC}; make configure)

do-install:
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	${MKDIR} ${ZOPEDIR}
	(cd ${WRKSRC}; pax -r -w -s'/.*\.[cho]$$//' . ${ZOPEDIR})
	${PREFIX}/bin/python \
		${PREFIX}/lib/python1.5/compileall.py ${ZOPEDIR}
	chmod -R a+rX ${ZOPEDIR}
	(cd ${PREFIX}; find zope -type f -print >>${PLIST_SRC})
	(cd ${PREFIX}; find -d zope -type d -print | \
	${SED} -e "s/^/@dirrm /" >>${PLIST_SRC})
	${SED} -e "s,/usr/pkg,${PREFIX}," \
		<${FILESDIR}/zope-install.py >${PREFIX}/sbin/zope-install
	chmod 755 ${PREFIX}/sbin/zope-install

.include "../../mk/bsd.pkg.mk"
