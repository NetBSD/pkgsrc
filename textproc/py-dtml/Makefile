# $NetBSD: Makefile,v 1.9 2002/01/22 18:28:59 drochner Exp $
#

DISTNAME=	Zope-2.2.2-src
PKGNAME=	py-dtml-2.2.2
CATEGORIES=	textproc
MASTER_SITES=   http://www.zope.org/Products/Zope/2.2.2/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.zope.org/Documentation/Guides/DTML-HTML/DTML.html
COMMENT=	DTML and StructuredText from Zope, also independently useful

DEPENDS+=	py-extclass>=2.2.2:../../lang/py-extclass

PLIST_SRC=	${WRKDIR}/.PLIST_SRC
EXTRACT_ELEMENTS=	${DISTNAME}/lib/python/DocumentTemplate \
			${DISTNAME}/lib/python/StructuredText \
			${DISTNAME}/lib/python/ts_regex.py

WRKSRC=		${WRKDIR}/${DISTNAME}/lib/python/DocumentTemplate

do-configure:
	( cd ${WRKSRC} ;\
	  ${CP} ${PY_CONFIGDIR}/Makefile.pre.in . ;\
	  ${MAKE} -f Makefile.pre.in boot)

post-build:
	(cd ${WRKSRC}; make clean; ${RM} Makefile* sedscript release.* *.c)
	(cd ${WRKSRC}/..; ${PY_PROG} ${PY_LIBDIR}/compileall.py .)
	(cd ${WRKSRC}/..; ${PY_PROG} -O ${PY_LIBDIR}/compileall.py .)

do-install:
	${INSTALL_SCRIPT_DIR} ${PY_SITEPKG}
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	(cd ${WRKSRC}/..; ${PAX} -r -w -v -p p . ${PY_SITEPKG})
	(cd ${PREFIX}; ${FIND} ${PY_SITEPATH}/DocumentTemplate \
		${PY_SITEPATH}/StructuredText \
		-type f -print >>${PLIST_SRC})
	(cd ${PREFIX}; ${FIND} -d ${PY_SITEPATH}/DocumentTemplate \
		${PY_SITEPATH}/StructuredText \
		-type d -print | ${SED} -e "s/^/@dirrm /" >>${PLIST_SRC})

.include "../../lang/python20/Makefile.inc"
.include "../../mk/bsd.pkg.mk"

