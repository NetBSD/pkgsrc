# $NetBSD: Makefile,v 1.10 2002/01/05 14:31:01 tsarna Exp $
#

DISTNAME=	grail-06
PKGNAME=	grail-0.6
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.python.org/pub/grail/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://grail.sourceforge.net/
COMMENT=	Grail(TM) is a web browser written in Python

DEPENDS+=	py-Tk-2.0*:../../x11/py-Tk

BROKEN=		"Awaiting new release compatible with with Python 2.x"

USE_X11=	yes
NO_CONFIGURE=   yes
NO_BUILD=       yes

WRKSRC=		${WRKDIR}/grail-0.6
GRAILDIR=	share/misc/grail-0.6
PLIST_SRC=	${WRKDIR}/.PLIST_SRC

do-install:
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	${SED} -e "s,@PREFIX@,${PREFIX}," -e "s,@GRAILDIR@,${GRAILDIR}," \
		<${FILESDIR}/grail >${PREFIX}/bin/grail
	${CHMOD} 555 ${PREFIX}/bin/grail
	${CP} -R ${WRKSRC} ${PREFIX}/${GRAILDIR}
	${PREFIX}/bin/python \
		${PREFIX}/lib/python2.0/compileall.py ${PREFIX}/${GRAILDIR}
	(cd ${PREFIX}; ${FIND} ${GRAILDIR} -type f -print >>${PLIST_SRC})
	(cd ${PREFIX}; ${FIND} -d ${GRAILDIR} -type d -print | \
	${SED} -e "s/^/@dirrm /" >>${PLIST_SRC})

.include "../../mk/bsd.pkg.mk"
