# $NetBSD: Makefile,v 1.4 2003/06/02 01:16:14 jschauma Exp $

DISTNAME=	icewmconf-2.1.0
WRKSRC=		${WRKDIR}
CATEGORIES=	wm
MASTER_SITES=	http://sdboyd.dyndns.org/icewmconf/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://sdboyd.dyndns.org/icewmconf/
COMMENT=	Graphical configuration tool for IceWM

USE_BUILDLINK2=	# defined
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

.include "../../x11/tk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
