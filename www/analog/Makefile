# $NetBSD: Makefile,v 1.44 2004/10/11 18:06:31 tron Exp $

DISTNAME=       analog-5.32
CATEGORIES=	www
PKGREVISION=	1
MASTER_SITES=   ${HOMEPAGE} \
		http://www.web42.com/analog/ \
		http://www.statslab.cam.ac.uk/~sret1/analog/ \
		http://www.gekko.de/analog/

MAINTAINER=     tron@NetBSD.org
HOMEPAGE=	http://www.analog.cx/
COMMENT=	Extremely fast program for analysing WWW logfiles

WRKSRC=		${WRKDISTDIR}/src
ALL_TARGET=	analog
MAKE_ENV+=	PREFIX=${PREFIX} SYSCONFDIR=${PKG_SYSCONFDIR}
WRKDISTDIR=	${WRKDIR}/${DISTNAME}

USE_PKGINSTALL=	yes
EGDIR=		${PREFIX}/share/examples
CONF_FILES=	${EGDIR}/analog.cfg ${PKG_SYSCONFDIR}/analog.cfg

.if !exists(/usr/include/glob.h)
CFLAGS+=	-DNOGLOB
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKDISTDIR}/analog ${PREFIX}/bin
	${INSTALL_DATA} ${WRKDISTDIR}/analog.man ${PREFIX}/man/man1/analog.1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/analog \
	  ${PREFIX}/lib/analog/lang \
	  ${PREFIX}/lib/analog/images
	${INSTALL_DATA} ${WRKDISTDIR}/docs/* ${PREFIX}/share/doc/analog
	${INSTALL_DATA} ${WRKDISTDIR}/images/* ${PREFIX}/lib/analog/images
	${INSTALL_DATA} ${WRKDISTDIR}/lang/* ${PREFIX}/lib/analog/lang
	${INSTALL_DATA} -m 644 ${WRKDISTDIR}/analog.cfg \
	  ${PREFIX}/share/examples/analog.cfg

.include "../../mk/bsd.pkg.mk"
