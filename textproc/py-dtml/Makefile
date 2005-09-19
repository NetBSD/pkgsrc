# $NetBSD: Makefile,v 1.18 2005/09/19 15:25:41 hira Exp $
#

DISTNAME=	Zope-2.2.2-src
PKGNAME=	py-dtml-2.2.2
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=   http://www.zope.org/Products/Zope/2.2.2/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://www.zope.org/Documentation/Guides/DTML-HTML/DTML.html
COMMENT=	DTML and StructuredText from Zope, also independently useful

WRKSRC=		${WRKDIR}/${DISTNAME}/lib/python/DocumentTemplate
PLIST_SRC=	${WRKDIR}/.PLIST_SRC
EXTRACT_ELEMENTS=	${DISTNAME}/lib/python/DocumentTemplate \
			${DISTNAME}/lib/python/StructuredText \
			${DISTNAME}/lib/python/ts_regex.py

do-configure:
	(cd ${WRKSRC} && \
	  ${CP} ${PY_CONFIGDIR}/Makefile.pre.in . &&\
	  ${MAKE} -f Makefile.pre.in boot)

post-build:
	cd ${WRKSRC} && make clean && ${RM} Makefile* sedscript release.* *.c
	cd ${WRKSRC}/.. && ${PY_PROG} ${PY_LIBDIR}/compileall.py .
	cd ${WRKSRC}/.. && ${PY_PROG} -O ${PY_LIBDIR}/compileall.py .

do-install:
	${INSTALL_SCRIPT_DIR} ${PY_SITEPKG}
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	cd ${WRKSRC}/.. && ${PAX} -rw -pp . ${PY_SITEPKG}
	cd ${PREFIX} && ${FIND} ${PY_SITEPATH}/DocumentTemplate \
		${PY_SITEPATH}/StructuredText \
		-type f -print >>${PLIST_SRC}
	cd ${PREFIX} && ${FIND} ${PY_SITEPATH}/DocumentTemplate \
		${PY_SITEPATH}/StructuredText \
		-type d -print | ${SORT} -r | \
		${SED} -e "s/^/@dirrm /" >>${PLIST_SRC}

.include "../../lang/python20/Makefile.inc"

.include "../../lang/py-extclass/buildlink3.mk"
.include "../../lang/python20/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
