# $NetBSD: Makefile,v 1.9 2004/12/31 11:58:36 minskim Exp $

DISTNAME=	icewmconf-2.1.0
CATEGORIES=	wm
MASTER_SITES=	http://sdboyd.dyndns.org/icewmconf/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.sdboyd56.com/icewmconf/
COMMENT=	Graphical configuration tool for IceWM

WRKSRC=		${WRKDIR}
USE_BUILDLINK3=	yes
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

.include "../../x11/tk83/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
