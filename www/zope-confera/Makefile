# $NetBSD: Makefile,v 1.1.1.1 1999/05/03 15:23:49 tsarna Exp $
#

DISTNAME=	Confera-1.2.0-nonbin
PKGNAME=	zope-confera-1.2.0
CATEGORIES=	www
MASTER_SITES=   http://www.zope.org/Download/Prereleases/Confera/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.zope.org/

DEPENDS+=	zope-1.10.2:../../www/zope

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/lib

PLIST_SRC=	${WRKDIR}/.PLIST_SRC

ZOPEDIR=	${PREFIX}/zope
PRODPATH=		lib/python/Products/Confera

do-install:
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	(cd ${WRKDIR}; pax -r -w lib ${ZOPEDIR})
	chmod -R a+rX ${ZOPEDIR}/${PRODPATH}
	(cd ${PREFIX}; find zope/${PRODPATH} -type f -print >>${PLIST_SRC})
	${ECHO} "@dirrm zope/${PRODPATH}" >> ${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
