# $NetBSD: Makefile,v 1.2 2009/03/03 10:53:15 manu Exp $
#

PKGNAME=	${APACHE_PKG_PREFIX}-${DISTNAME}

COMMENT=	Simple Common Gateway Interface for Apache

PKG_DESTDIR_SUPPORT=	destdir

DEPENDS+=	${PYPKGPREFIX}-scgi:../../www/py-scgi

APACHE_MODULE= yes
.include "../../mk/apache.mk"

do-build:
	cd ${WRKSRC}/apache${APACHE_PKG_PREFIX:C/^ap(2)?.*/\1/} && \
	${APXS} -c mod_scgi.c

do-install:
	cd ${WRKSRC}/apache${APACHE_PKG_PREFIX:C/^ap(2)?.*/\1/} && \
	${APXS} -i mod_scgi.la

.include "../../lang/python/pyversion.mk"
.include "../../www/py-scgi/Makefile.common"
