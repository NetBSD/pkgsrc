# $NetBSD: Makefile,v 1.6 2002/01/16 12:45:00 tron Exp $
#

DISTNAME=	mxDateTime-1.3.0
PKGNAME=	${PYPKGPREFIX}-mxDateTime-1.3.0
WRKSRC=         ${WRKDIR}/DateTime
CATEGORIES=	time
MASTER_SITES=	http://starship.python.net/~lemburg/
EXTRACT_SUFX=   .zip

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://starship.python.net/~lemburg/mxDateTime.html
COMMENT=	Python extension that provides new types and conversions for dates

EXTRACT_CMD=	unzip -Laqo ${DOWNLOADED_DISTFILE}

RESTRICTED=	No commercial distribution
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

PYTHON_VERSIONS_ACCEPTED=	21 # 20 and 22 doen't work
USE_PYPKGPREFIX=	yes
PY_PATCHPLIST=		yes

do-configure:
	( cd ${WRKSRC}/mxDateTime; ${MAKE_PROGRAM} -f Makefile.pre.in boot PYTHONBIN=${PYTHONBIN})

do-build:
	( cd ${WRKSRC}/mxDateTime; ${MAKE_PROGRAM} )
	( cd ${WRKSRC}; ${PYTHONBIN} ${PREFIX}/${PYLIB}/compileall.py . )
	( cd ${WRKSRC}; ${PYTHONBIN} -O ${PREFIX}/${PYLIB}/compileall.py . )

do-install:
	@${INSTALL_SCRIPT_DIR} ${PREFIX}/${PYSITELIB}/DateTime
	${INSTALL_DATA} ${WRKSRC}/*.py* \
		${PREFIX}/${PYSITELIB}/DateTime
	${INSTALL_SCRIPT_DIR} \
		${PREFIX}/${PYSITELIB}/DateTime/mxDateTime
	${INSTALL_DATA} ${WRKSRC}/mxDateTime/*.so \
		${WRKSRC}/mxDateTime/__init__.py* \
		 ${PREFIX}/${PYSITELIB}/DateTime/mxDateTime

.include "../../lang/python/extension.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
