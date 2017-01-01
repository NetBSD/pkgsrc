# $NetBSD: Makefile,v 1.18 2017/01/01 14:44:02 wiz Exp $
#

PKGNAME=	${APACHE_PKG_PREFIX}-${DISTNAME}

COMMENT=	Simple Common Gateway Interface for Apache
LICENSE=	cnri-license

DEPENDS+=	${PYPKGPREFIX}-scgi-[0-9]*:../../www/py-scgi

APACHE_MODULE= yes

# does not compile with apache24
PKG_APACHE_ACCEPTED=	apache22

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-quixote via py-scgi

MODULE_EXT=	la
APACHE_MODULE_SRCDIR=	${WRKDIR}/${DISTNAME}/apache2

APACHE_MODULE_NAME=	mod_scgi.${MODULE_EXT}
APACHE_MODULE_SRC=	mod_scgi.c

.include "../../lang/python/pyversion.mk"
.include "../../mk/apache.module.mk"
.include "../../www/py-scgi/Makefile.common"
