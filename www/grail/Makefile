# $NetBSD: Makefile,v 1.3 1998/08/24 00:12:49 tsarna Exp $
#

DISTNAME=	grail_04
PKGNAME=	grail-0.4
CATEGORIES=	www
MASTER_SITES=	http://monty.cnri.reston.va.us/grail-0.4/source/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://grail.cnri.reston.va.us/grail/

DEPENDS+=       python-1.5.1:../../lang/python
DEPENDS+=	py-Tk-1.5.1:../../x11/py-Tk

NO_CONFIGURE=   yes
NO_BUILD=       yes

WRKSRC=		${WRKDIR}/grail-0.4
GRAILDIR=	share/misc/grail-0.4
PLIST_SRC=	${WRKDIR}/.PLIST_SRC

do-install:
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	${SED} -e "s,@PREFIX@,${PREFIX}," -e "s,@GRAILDIR@,${GRAILDIR}," \
		<${FILESDIR}/grail >${PREFIX}/bin/grail
	chmod 555 ${PREFIX}/bin/grail
	${CP} -R ${WRKSRC} ${PREFIX}/${GRAILDIR}
	${PREFIX}/bin/python \
		${PREFIX}/lib/python1.5/compileall.py ${PREFIX}/${GRAILDIR}
	(cd ${PREFIX}; find ${GRAILDIR} -type f -print >>${PLIST_SRC})
	(cd ${PREFIX}; find -d ${GRAILDIR} -type d -print | \
	${SED} -e "s/^/@dirrm /" >>${PLIST_SRC})

.include "../../mk/bsd.pkg.mk"
