# $NetBSD: Makefile,v 1.14 2014/06/11 12:57:23 joerg Exp $
#

PKGNAME=	${APACHE_PKG_PREFIX}-${DISTNAME}
PKGREVISION=	2

COMMENT=	Simple Common Gateway Interface for Apache

DEPENDS+=	${PYPKGPREFIX}-scgi-[0-9]*:../../www/py-scgi

APACHE_MODULE= yes

# does not compile with apache24
PKG_APACHE_ACCEPTED=	apache22

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-quixote via py-scgi

MODULE_EXT=	la
APACHE_MODULE_SRCDIR=	${WRKDIR}/${DISTNAME}/apache2

APACHE_MODULE_NAME=	mod_scgi.${MODULE_EXT}
APACHE_MODULE_SRC=	mod_scgi.c

.include "../../lang/python/pyversion.mk"
.include "../../mk/apache.module.mk"
.include "../../www/py-scgi/Makefile.common"
