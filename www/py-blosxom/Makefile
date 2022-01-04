# $NetBSD: Makefile,v 1.29 2022/01/04 20:55:16 wiz Exp $

PYBLOXSOMVERS=	1.5.3
DISTNAME=	pyblosxom-${PYBLOXSOMVERS}
PKGNAME=	${PYPKGPREFIX}-blosxom-${PYBLOXSOMVERS}
PKGREVISION=	5
CATEGORIES=	www
MASTER_SITES=	http://pyblosxom.github.com/download/

MAINTAINER=	hauke@NetBSD.org
HOMEPAGE=	https://pyblosxom.github.com/
COMMENT=	PyBlosxom is a lightweight file-based weblog system

LICENSE=	mit

DIST_SUBDIR=	${DISTNAME}	# upstream reissued tarball with no changes

USE_LANGUAGES=	#none

DOC_SUBDIR=	share/doc/pyblosxom
DOCDIR=		${PREFIX}/${DOC_SUBDIR}
DOCFILES=	AUTHORS INSTALL LICENSE README.rst UPGRADE WHATSNEW

BUILD_DEPENDS+=	${PYPKGPREFIX}-pygments<2.6:../../textproc/py-pygments25
BUILD_DEPENDS+=	${PYPKGPREFIX}-docutils>=0.12:../../textproc/py-docutils

INSTALLATION_DIRS=		${DOC_SUBDIR}

REPLACE_PYTHON=			Pyblosxom/data/pyblosxom.cgi

PYTHON_VERSIONS_ACCEPTED=	27

pre-configure:
	cd ${WRKSRC} && ${FIND} Pyblosxom -type f -name '*.orig' \
		-exec ${RM} -f \{\} \;

# There is a set of manual files in docs/source that could be
# converted to HTML or PDF, and installed
post-install:
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${DOCDIR}/${f}
.endfor

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
