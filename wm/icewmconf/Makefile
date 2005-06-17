# $NetBSD: Makefile,v 1.12 2005/06/17 03:50:39 jlam Exp $

DISTNAME=	icewmconf-2.1.0
PKGREVISION=	1
CATEGORIES=	wm
MASTER_SITES=	http://sdboyd.dyndns.org/icewmconf/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.sdboyd56.com/icewmconf/
COMMENT=	Graphical configuration tool for IceWM

DEPENDS+=	tk-[0-9]*:../../x11/tk

WRKSRC=		${WRKDIR}
FILENAME=	${WRKDIR}/${DISTNAME:C/-.*//}
NO_BUILD=	# defined

INSTALLATION_DIRS=	bin

post-extract:
	${MV} ${WRKDIR}/${DISTNAME} ${FILENAME}

post-patch:
	${MV} ${FILENAME} ${FILENAME}.orig
	${SED} 's#PREFIX#${X11PREFIX}#g' \
		< ${FILENAME}.orig > ${FILENAME}

do-install:
	${INSTALL_SCRIPT} ${FILENAME} ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
