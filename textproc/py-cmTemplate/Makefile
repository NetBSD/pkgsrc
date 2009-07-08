# $NetBSD: Makefile,v 1.4 2009/07/08 13:56:00 joerg Exp $
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

INSTALLATION_DIRS=	${PYSITELIB} share/doc/${PYPKGPREFIX}-cmTemplate

do-build:
	${PY_COMPILE_ALL} -l ${WRKSRC}

do-install:
	${INSTALL_DATA} ${WRKSRC}/cmTemplate.py ${DESTDIR}${PREFIX}/${PYSITELIB}
	${INSTALL_DATA} ${WRKSRC}/cmTemplate.pyc ${DESTDIR}${PREFIX}/${PYSITELIB}
	${INSTALL_DATA} ${WRKSRC}/doc/cmTemplate.html ${DESTDIR}${PREFIX}/share/doc/${PYPKGPREFIX}-cmTemplate

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
