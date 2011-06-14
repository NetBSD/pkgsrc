# $NetBSD: Makefile,v 1.6 2011/06/14 11:10:54 obache Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes

WRKSRC=${WRKDIR}/pyExcelerator-${VERSION}

INSTALLATION_DIRS=	share/doc/py-Excelerator share/examples/py-Excelerator

post-install:
	for f in CHANGES.txt LICENSE.txt README.txt THANKS.txt TODO.txt ; do \
		${INSTALL_DATA} ${WRKSRC}/$$f ${DESTDIR}${PREFIX}/share/doc/py-Excelerator/ ; \
	done
	for f in ${WRKSRC}/examples/*.py ${WRKSRC}/tools/*.py ; do \
		${INSTALL_DATA} $$f ${DESTDIR}${PREFIX}/share/examples/py-Excelerator/ ; \
	done

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
