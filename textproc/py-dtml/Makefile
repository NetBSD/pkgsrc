# $NetBSD: Makefile,v 1.1.1.1 2000/01/02 04:48:45 tsarna Exp $
#

DISTNAME=	Zope-2.1.1-src
PKGNAME=	py-dtml-2.1.1
CATEGORIES=	textproc
MASTER_SITES=   http://www.zope.org/Products/Zope/2.1.1/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.zope.org/Documentation/Guides/DTML-HTML/DTML.html

DEPENDS+=	py-extclass-2.1.1:../../lang/python

ALL_TARGET=	default
PLIST_SRC=	${WRKDIR}/.PLIST_SRC
SITE_PKG=		lib/python1.5/site-packages
PYTHON_LIBDIR=		${LOCALBASE}/${SITE_PKG}
PYTHON_CONFIGDIR=	${LOCALBASE}/lib/python1.5/config
EXTRACT_ELEMENTS=	Zope-2.1.1-src/lib/python/DocumentTemplate \
			Zope-2.1.1-src/lib/python/StructuredText \
			Zope-2.1.1-src/lib/python/ts_regex.py

WRKSRC=		${WRKDIR}/Zope-2.1.1-src/lib/python/DocumentTemplate

do-configure:
	( cd ${WRKSRC} ;\
	  ${CP} ${PYTHON_CONFIGDIR}/Makefile.pre.in . ;\
	  ${MAKE} -f Makefile.pre.in boot)

post-build:
	(cd ${WRKSRC}; make clean; ${RM} Makefile* sedscript release.* *.c)
	(cd ${WRKSRC}/..; ${LOCALBASE}/bin/python ${PREFIX}/lib/python1.5/compileall.py .)
	(cd ${WRKSRC}/..; ${LOCALBASE}/bin/python -O ${PREFIX}/lib/python1.5/compileall.py .)

do-install:
	${INSTALL_SCRIPT_DIR} ${PYTHON_LIBDIR}
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	(cd ${WRKSRC}/..; ${PAX} -r -w -v -p e . ${PYTHON_LIBDIR})
	(cd ${PREFIX}; ${FIND} ${SITE_PKG}/DocumentTemplate \
		${SITE_PKG}/StructuredText \
		-type f -print >>${PLIST_SRC})
	(cd ${PREFIX}; ${FIND} -d ${SITE_PKG}/DocumentTemplate \
		${SITE_PKG}/StructuredText \
		-type d -print | ${SED} -e "s/^/@dirrm /" >>${PLIST_SRC})

.include "../../mk/bsd.pkg.mk"
