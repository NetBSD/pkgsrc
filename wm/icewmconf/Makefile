# $NetBSD: Makefile,v 1.18 2012/10/08 12:42:21 asau Exp $

DISTNAME=	icewmconf-2.1.0
PKGREVISION=	2
CATEGORIES=	wm
MASTER_SITES=	# http://sdboyd.dyndns.org/icewmconf/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.sdboyd56.com/icewmconf/
COMMENT=	Graphical configuration tool for IceWM

DEPENDS+=	tk-[0-9]*:../../x11/tk

WRKSRC=		${WRKDIR}
FILENAME=	${WRKDIR}/${DISTNAME:C/-.*//}
NO_BUILD=	yes

INSTALLATION_DIRS=	bin

post-extract:
	${MV} ${WRKDIR}/${DISTNAME} ${FILENAME}

post-patch:
	${MV} ${FILENAME} ${FILENAME}.orig
	${SED} 's#PREFIX#${X11PREFIX}#g' \
		< ${FILENAME}.orig > ${FILENAME}

do-install:
	${INSTALL_SCRIPT} ${FILENAME} ${DESTDIR}${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
