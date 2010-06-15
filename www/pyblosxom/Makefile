# $NetBSD: Makefile,v 1.1.1.1 2010/06/15 14:06:08 hauke Exp $
#

PYBLOXSOMVERS=	1.5
DISTNAME=	pyblosxom-${PYBLOXSOMVERS}-rc1
PKGNAME=	${PYPKGPREFIX}-pyblosxom-${PYBLOXSOMVERS}
CATEGORIES=	www
MASTER_SITES=	http://pyblosxom.bluesock.org/download/

MAINTAINER=	hauke@NetBSD.org
HOMEPAGE=	http://pyblosxom.bluesock.org/
COMMENT=	PyBlosxom is a lightweight file-based weblog system

LICENSE=	mit

DOC_SUBDIR=     share/doc/pyblosxom
DOCDIR=         ${PREFIX}/${DOC_SUBDIR}
DOCFILES=       AUTHORS CHANGELOG INSTALL LICENSE README THANKS TODO UPGRADE

INSTALLATION_DIRS=	${DOC_SUBDIR}

REPLACE_PYTHON=		${WRKSRC}/*.py

PKG_DESTDIR_SUPPORT=	user-destdir

# There is a set of manual files in docs/source that could be
# converted to HTML or PDF, and installed
post-install:
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${DOCDIR}/${f}
.endfor

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
