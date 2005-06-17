# $NetBSD: Makefile,v 1.12 2005/06/17 03:50:43 jlam Exp $
#

DISTNAME=	Confera-1.2.0-nonbin
PKGNAME=	zope-confera-1.2.0
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=   http://www.zope.org/Download/Prereleases/Confera/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://www.zope.org/
COMMENT=	Confera: Threaded discussion groups for Zope

DEPENDS+=	zope>=2.1.4:../../www/zope

WRKSRC=		${WRKDIR}/lib
NO_BUILD=	yes

PLIST_SRC=	${WRKDIR}/.PLIST_SRC

ZOPEDIR=	${PREFIX}/lib/zope
PRODPATH=	lib/python/Products/Confera

do-install:
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	${INSTALL_DATA_DIR} ${ZOPEDIR}
	cd ${WRKDIR} && ${PAX} -rw lib ${ZOPEDIR}
	${CHMOD} -R a+rX ${ZOPEDIR}/${PRODPATH}
	cd ${PREFIX} && ${FIND} lib/zope/${PRODPATH} -type f -print >>${PLIST_SRC}
	${ECHO} "@dirrm lib/zope/${PRODPATH}" >> ${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
