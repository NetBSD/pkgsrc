# $NetBSD: Makefile,v 1.3 1999/12/08 14:23:45 rh Exp $
#

DISTNAME=	Confera-1.2.0-nonbin
PKGNAME=	zope-confera-1.2.0
CATEGORIES=	www
MASTER_SITES=   http://www.zope.org/Download/Prereleases/Confera/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.zope.org/

DEPENDS+=	zope-*:../../www/zope

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/lib

PLIST_SRC=	${WRKDIR}/.PLIST_SRC

ZOPEDIR=	${PREFIX}/lib/zope
PRODPATH=	lib/python/Products/Confera

do-install:
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	(cd ${WRKDIR}; pax -r -w lib ${ZOPEDIR})
	chmod -R a+rX ${ZOPEDIR}/${PRODPATH}
	(cd ${PREFIX}; find lib/zope/${PRODPATH} -type f -print >>${PLIST_SRC})
	${ECHO} "@dirrm lib/zope/${PRODPATH}" >> ${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
