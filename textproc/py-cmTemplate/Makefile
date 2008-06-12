# $NetBSD: Makefile,v 1.3 2008/06/12 02:14:52 joerg Exp $
#

DISTNAME=		cmTemplate-0.3.2
PKGNAME=	${PYPKGPREFIX}-cmTemplate-0.3.2
CATEGORIES=		textproc python
MASTER_SITES=		http://www.bouncingchairs.net/oss/

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://www.bouncingchairs.net/oss/
COMMENT=		Simple and fast Python template engine

PKG_DESTDIR_SUPPORT=	user-destdir

PY_PATCHPLIST=	# empty
PLIST_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX}
PYCOMPILEALL=	${BUILDLINK_PREFIX.${PYPACKAGE}}/${PYLIB}/compileall.py

INSTALLATION_DIRS=	${PYSITELIB} share/doc/${PYPKGPREFIX}-cmTemplate

do-build:
	${PYTHONBIN} ${PYCOMPILEALL} -l ${WRKSRC}

do-install:
	${INSTALL_DATA} ${WRKSRC}/cmTemplate.py ${DESTDIR}${PREFIX}/${PYSITELIB}
	${INSTALL_DATA} ${WRKSRC}/cmTemplate.pyc ${DESTDIR}${PREFIX}/${PYSITELIB}
	${INSTALL_DATA} ${WRKSRC}/doc/cmTemplate.html ${DESTDIR}${PREFIX}/share/doc/${PYPKGPREFIX}-cmTemplate

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
