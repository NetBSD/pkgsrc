# $NetBSD: Makefile,v 1.26 2007/10/06 00:16:28 joerg Exp $
#

DISTNAME=	grail-0.6
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=grail/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://grail.sourceforge.net/
COMMENT=	Grail(TM) is a web browser written in Python

NO_BUILD=	yes

GRAILDIR=	share/misc/grail-0.6
PLIST_SRC=	${WRKDIR}/.PLIST_SRC
PYTHON_VERSIONS_ACCEPTED= 15

REPLACE_PYTHON=	grsh.py

INSTALLATION_DIRS=	bin share/misc

do-configure:

do-install:
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	${SED} -e "s,@PREFIX@,${PREFIX}," \
		-e "s,@GRAILDIR@,${GRAILDIR}," \
		-e "s,@PYTHONBIN@,${PYTHONBIN}," \
		<${FILESDIR}/grail >${PREFIX}/bin/grail
	${CHMOD} 555 ${PREFIX}/bin/grail
	${CP} -R ${WRKSRC} ${PREFIX}/${GRAILDIR}
	${PYTHONBIN} ${PREFIX}/lib/python${PYVERSSUFFIX}/compileall.py \
		${PREFIX}/${GRAILDIR}
	(cd ${PREFIX}; ${FIND} ${GRAILDIR} -type f -print >>${PLIST_SRC})
	(cd ${PREFIX}; ${FIND} -d ${GRAILDIR} -type d -print | \
	${SED} -e "s/^/@dirrm /" >>${PLIST_SRC})

.include "../../lang/python/application.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
