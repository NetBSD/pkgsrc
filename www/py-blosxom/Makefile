# $NetBSD: Makefile,v 1.8 2012/01/26 19:52:57 hauke Exp $
#

PYBLOXSOMVERS=	1.5.2
DISTNAME=	pyblosxom-${PYBLOXSOMVERS}
PKGNAME=	${PYPKGPREFIX}-blosxom-${PYBLOXSOMVERS}
CATEGORIES=	www
MASTER_SITES=	http://pyblosxom.bluesock.org/download/

MAINTAINER=	hauke@NetBSD.org
HOMEPAGE=	http://pyblosxom.bluesock.org/
COMMENT=	PyBlosxom is a lightweight file-based weblog system

LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_ACCEPTED=	27 26 25

DIST_SUBDIR=	${DISTNAME}	# upstream reissued tarball with no changes
DOC_SUBDIR=     share/doc/pyblosxom
DOCDIR=         ${PREFIX}/${DOC_SUBDIR}
DOCFILES=       AUTHORS INSTALL LICENSE README.rst UPGRADE WHATSNEW

INSTALLATION_DIRS=	${DOC_SUBDIR}

REPLACE_PYTHON=		Pyblosxom/data/pyblosxom.cgi
EGG_NAME=		${DISTNAME}

# There is a set of manual files in docs/source that could be
# converted to HTML or PDF, and installed
post-install:
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${DOCDIR}/${f}
.endfor

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
