# $NetBSD: Makefile,v 1.2 2010/08/06 14:46:16 hauke Exp $
#

PYBLOXSOMVERS=	1.5
DISTNAME=	pyblosxom-${PYBLOXSOMVERS}rc2
PKGNAME=	${PYPKGPREFIX}-blosxom-${PYBLOXSOMVERS}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://pyblosxom.bluesock.org/download/

MAINTAINER=	hauke@NetBSD.org
HOMEPAGE=	http://pyblosxom.bluesock.org/
COMMENT=	PyBlosxom is a lightweight file-based weblog system

LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

DOC_SUBDIR=     share/doc/pyblosxom
DOCDIR=         ${PREFIX}/${DOC_SUBDIR}
DOCFILES=       AUTHORS CHANGELOG INSTALL LICENSE README THANKS TODO UPGRADE

# Mend author's spelling mitsake
WRKSRC=		${WRKDIR}/pybloxsom-1.5rc2

INSTALLATION_DIRS=	${DOC_SUBDIR}

REPLACE_PYTHON=		${WRKSRC}/*.py
EGG_NAME=		${DISTNAME}

# There is a set of manual files in docs/source that could be
# converted to HTML or PDF, and installed
post-install:
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${DOCDIR}/${f}
.endfor

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
