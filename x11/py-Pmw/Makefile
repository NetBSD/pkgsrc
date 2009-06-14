# $NetBSD: Makefile,v 1.26 2009/06/14 22:13:25 joerg Exp $
#

DISTNAME=	Pmw.1.2
PKGNAME=	${PYPKGPREFIX}-Pmw-1.2
PKGREVISION=	1
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pmw/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pmw.sourceforge.net/
COMMENT=	Python meta widgets

PKG_DESTDIR_SUPPORT=	user-destdir

PLIST_SRC=	${WRKDIR}/.PLIST_SRC

WRKSRC=		${WRKDIR}/Pmw

NO_BUILD=	yes

do-install:
	(cd ${WRKDIR}; ${FIND} Pmw -type d -print | \
	    ${SED} -e 's,^,${DESTDIR}${PREFIX}/${PYSITELIB}/,' | ${XARGS} -n 1 ${INSTALL_DATA_DIR})
	(cd ${WRKDIR}; for f in `${FIND} Pmw -type f -print`; do \
	    ${INSTALL_DATA} $$f ${DESTDIR}${PREFIX}/${PYSITELIB}/$$f; done)
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	(cd ${DESTDIR}${PREFIX}; ${FIND} ${PYSITELIB}/Pmw \
		-type f -print >>${PLIST_SRC})

.include "../../lang/python/extension.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../x11/blt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
