# $NetBSD: Makefile,v 1.5 2011/07/08 09:59:19 hauke Exp $
#

PYBLOXSOMVERS=	1.5
DISTNAME=	pyblosxom-${PYBLOXSOMVERS}rc3
PKGNAME=	${PYPKGPREFIX}-blosxom-${PYBLOXSOMVERS}
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://pyblosxom.bluesock.org/download/

MAINTAINER=	hauke@NetBSD.org
HOMEPAGE=	http://pyblosxom.bluesock.org/
COMMENT=	PyBlosxom is a lightweight file-based weblog system

LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

DIST_SUBDIR=	${DISTNAME}	# upstream reissued tarball with no changes
DOC_SUBDIR=     share/doc/pyblosxom
DOCDIR=         ${PREFIX}/${DOC_SUBDIR}
DOCFILES=       AUTHORS CHANGELOG INSTALL LICENSE README THANKS TODO UPGRADE

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
