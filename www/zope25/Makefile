# $NetBSD: Makefile,v 1.6 2003/05/02 11:56:47 wiz Exp $
#

DISTNAME=	Zope-2.6.1-src
PKGREVISION=	1
PKGNAME=	zope-2.6.1
CATEGORIES=	www
MASTER_SITES=	http://www.zope.org/Products/Zope/2.6.1/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.zope.org/
COMMENT=	Zope, the Z Object Publishing Environment

DIST_SUBDIR=	zope

PYTHON_VERSIONS_ACCEPTED=	21pth
USE_BUILDLINK2=	yes

ZOPEDIR=	${PREFIX}/lib/zope
ZOPEPY=		pcgi lib/python ZServer z2.py zpasswd.py
ZOPEDATA=	Extensions doc import var inst utilities

#do-build:
#	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHONBIN} w_pcgi.py)

do-build:
	(cd ${WRKSRC}/pcgi && ${SETENV} ${MAKE_ENV} ./configure && \
		${SETENV} ${MAKE_ENV} ${MAKE})
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PYTHONBIN} inst/build_extensions.py)

#
# Install code and prototype data. A real INSTANCE_HOME must be created
# outside of ${PREFIX} to allow shared, read-only installations.
#
do-install:
	${INSTALL_DATA_DIR} ${ZOPEDIR}
	cd ${WRKSRC} && ${FIND} ${ZOPEPY} -type f -and \! \( -name "*.[cho]" \
		-or -name "sedscript" -or -name "Makefile*" \
		-or -name "Setup*" -or -name ".cvsignore" \) \
		-print | ${PAX} -rw ${ZOPEDIR}
	cd ${ZOPEDIR} && ${PYTHONBIN} ${WRKSRC}/inst/compilezpy.py
	cd ${WRKSRC} && ${PAX} -rw ${ZOPEDATA} ${ZOPEDIR}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
