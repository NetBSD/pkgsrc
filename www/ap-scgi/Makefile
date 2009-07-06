# $NetBSD: Makefile,v 1.4 2009/07/06 16:05:45 joerg Exp $
#

PKGNAME=	${APACHE_PKG_PREFIX}-${DISTNAME}

COMMENT=	Simple Common Gateway Interface for Apache

PKG_DESTDIR_SUPPORT=	destdir

DEPENDS+=	${PYPKGPREFIX}-scgi-[0-9]*:../../www/py-scgi

APACHE_MODULE= yes
.include "../../mk/apache.mk"

.if ${APACHE_PKG_PREFIX} == "ap13"
WRKSRC=	${WRKDIR}/${DISTNAME}/apache1
.else
WRKSRC=	${WRKDIR}/${DISTNAME}/apache2
.endif

do-build:
	cd ${WRKSRC} && ${APXS} -c mod_scgi.c

.if ${APACHE_PKG_PREFIX} == "ap13"
do-install:
	cd ${WRKSRC} && ${APXS} -i mod_scgi.so
.else
do-install:
	cd ${WRKSRC} && ${APXS} -i mod_scgi.la
.endif

.include "../../lang/python/pyversion.mk"
.include "../../www/py-scgi/Makefile.common"
