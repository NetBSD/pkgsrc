# $NetBSD: Makefile,v 1.1.1.1 2002/02/28 11:29:16 martti Exp $

DISTNAME=	icewmconf-2.1.0
CATEGORIES=	wm
MASTER_SITES=	http://sdboyd.dyndns.org/icewmconf/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://sdboyd.dyndns.org/icewmconf/
COMMENT=	Graphical configuration tool for IceWM

WRKSRC=		${WRKDIR}
FILENAME=	${WRKDIR}/${DISTNAME:C/-.*//}
NO_BUILD=	# defined

post-extract:
	${MV} ${WRKDIR}/${DISTNAME} ${FILENAME}

post-patch:
	${MV} ${FILENAME} ${FILENAME}.orig
	${SED} 's#PREFIX#${X11PREFIX}#g' \
		< ${FILENAME}.orig > ${FILENAME}

do-install:
	${INSTALL_SCRIPT} ${FILENAME} ${PREFIX}/bin/

.include "../../x11/tk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
