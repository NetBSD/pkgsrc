# $NetBSD: Makefile,v 1.50 2005/08/25 10:09:48 grant Exp $

DISTNAME=       analog-6.0
CATEGORIES=	www
MASTER_SITES=   ${HOMEPAGE} \
		http://www.web42.com/analog/ \
		http://analog.org/loganalysis/ \
		http://www.gekko.de/analog/

MAINTAINER=     tron@NetBSD.org
HOMEPAGE=	http://www.analog.cx/
COMMENT=	Extremely fast program for analysing WWW logfiles

WRKSRC=		${WRKDISTDIR}/src
BUILD_TARGET=	analog
MAKE_ENV+=	PREFIX=${PREFIX} SYSCONFDIR=${PKG_SYSCONFDIR}
WRKDISTDIR=	${WRKDIR}/${DISTNAME}

USE_PKGINSTALL=	yes
EGDIR=		${PREFIX}/share/examples
CONF_FILES=	${EGDIR}/analog.cfg ${PKG_SYSCONFDIR}/analog.cfg

.if !exists(/usr/include/glob.h)
CFLAGS+=	-DNOGLOB
.endif

INSTALLATION_DIRS=	bin man/man1

LIBS+=		-lm
LIBS.SunOS+=	-lnsl -lsocket
MAKE_ENV+=	LIBS=${LIBS:Q}

do-install:
	${INSTALL_PROGRAM} ${WRKDISTDIR}/analog ${PREFIX}/bin
	${INSTALL_DATA} ${WRKDISTDIR}/analog.man ${PREFIX}/man/man1/analog.1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/analog
	${INSTALL_DATA_DIR} ${PREFIX}/lib/analog/lang
	${INSTALL_DATA_DIR} ${PREFIX}/lib/analog/images
	${INSTALL_DATA} ${WRKDISTDIR}/docs/* ${PREFIX}/share/doc/analog
	${INSTALL_DATA} ${WRKDISTDIR}/images/* ${PREFIX}/lib/analog/images
	${INSTALL_DATA} ${WRKDISTDIR}/lang/* ${PREFIX}/lib/analog/lang
	${INSTALL_DATA} -m 644 ${WRKDISTDIR}/analog.cfg \
		${PREFIX}/share/examples/analog.cfg

.include "../../mk/bsd.pkg.mk"
