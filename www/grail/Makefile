# $NetBSD: Makefile,v 1.2 1998/08/20 15:17:30 tsarna Exp $
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

EXTRACT_ONLY=
NO_CONFIGURE=   yes
NO_BUILD=       yes

WRKSRC=		${WRKDIR}/grail-0.4
GRAILBASE=	share/misc
GRAILDIR=	${GRAILBASE}/grail-0.4
PLIST_SRC=	${WRKDIR}/.PLIST_SRC

do-install:
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	${SED} -e "s,@PREFIX@,${PREFIX}," -e "s,@GRAILDIR@,${GRAILDIR}," \
		<${FILESDIR}/grail >${PREFIX}/bin/grail
	chmod 555 ${PREFIX}/bin/grail
	(cd ${PREFIX}/${GRAILBASE}; \
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} \
		${EXTRACT_AFTER_ARGS})
	${PREFIX}/bin/python \
		${PREFIX}/lib/python1.5/compileall.py ${PREFIX}/${GRAILDIR}
	(cd ${PREFIX}; find ${GRAILDIR} -type f -print >>${PLIST_SRC})
	(cd ${PREFIX}; find -d ${GRAILDIR} -type d -print | \
	${SED} -e "s/^/@dirrm /" >>${PLIST_SRC})

.include "../../mk/bsd.pkg.mk"
