# $NetBSD: Makefile,v 1.1.1.1 2008/03/08 00:18:25 mjl Exp $
#

DISTNAME=	pyexcelerator-${VERSION}
PKGNAME=	${PYPKGPREFIX}-Excelerator-${VERSION}
VERSION=	0.6.3a
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyexcelerator/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/pyexcelerator/
COMMENT=	Python library for generating Excel 97/2000/XP/2003 files

PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_ACCEPTED=	24 25

# No -L please, needs upper case
EXTRACT_OPTS_ZIP=-aqo

WRKSRC=${WRKDIR}/pyExcelerator-${VERSION}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/docs/py-Excelerator
	for f in CHANGES.txt LICENSE.txt README.txt THANKS.txt TODO.txt ; do \
		${INSTALL_DATA} ${WRKSRC}/$$f ${PREFIX}/docs/py-Excelerator/ ; \
	done
	${INSTALL_DATA_DIR} ${PREFIX}/examples/py-Excelerator
	for f in ${WRKSRC}/examples/*.py ${WRKSRC}/tools/*.py ; do \
		${INSTALL_DATA} $$f ${PREFIX}/examples/py-Excelerator/ ; \
	done

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
