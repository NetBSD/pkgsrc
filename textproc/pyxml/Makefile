# $NetBSD: Makefile,v 1.1.1.1 2001/03/07 12:14:59 drochner Exp $
#

DISTNAME=	PyXML-0.6.4
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyxml/}

MAINTAINER=	drochner@netbsd.org
HOMEPAGE=	http://pyxml.sourceforge.net/
COMMENT=	collection of libraries to process XML with Python

DEPENDS+=	python>=2.0:../../lang/python
DEPENDS+=	expat-*:../../textproc/expat

.if ${MACHINE_ARCH} == "powerpc" || ${MACHINE_ARCH} == "mips" || ${MACHINE_ARCH} == "vax"
IGNORE="${PKGNAME} needs dynamic loading"
.endif

PLIST_SRC=	${WRKDIR}/.PLIST_SRC
EVAL_PREFIX+=	PYPREFIX=python

do-build:
	(cd ${WRKSRC} && ${PYPREFIX}/bin/python setup.py build)

post-build:
	(eval `${PYPREFIX}/bin/python ${FILESDIR}/printpypath.py` && \
	${SED} "s|PYINC|$${PYINC}|g;s|PYSITELIB|$${PYSITELIB}|g" \
	<${PKGDIR}/PLIST >${PLIST_SRC})

do-install:
	(cd ${WRKSRC} && ${PYPREFIX}/bin/python setup.py install)

.include "../../mk/bsd.pkg.mk"
