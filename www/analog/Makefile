# $NetBSD: Makefile,v 1.24 2001/05/14 12:42:14 tron Exp $

DISTNAME=       analog-5.0
CATEGORIES=	www
MASTER_SITES=   ${HOMEPAGE} \
		http://www.web42.com/analog/ \
		http://www.statslab.cam.ac.uk/~sret1/analog/ \
		http://www.gekko.de/analog/

MAINTAINER=     tron@netbsd.org
HOMEPAGE=	http://www.analog.cx/
COMMENT=	Extremely fast program for analysing WWW logfiles

ALL_TARGET=	analog
MAKE_ENV+=	PREFIX=${PREFIX}
WRKDISTDIR=	${WRKDIR}/${DISTNAME}
WRKSRC=		${WRKDISTDIR}/src

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/analog \
	  ${PREFIX}/lib/analog/lang \
	  ${PREFIX}/lib/analog/images
	${INSTALL_DATA} ${WRKDISTDIR}/docs/* ${PREFIX}/share/doc/analog
	${INSTALL_DATA} ${WRKDISTDIR}/images/* ${PREFIX}/lib/analog/images
	${INSTALL_DATA} ${WRKDISTDIR}/lang/* ${PREFIX}/lib/analog/lang
	${INSTALL_PROGRAM} ${WRKDISTDIR}/analog ${PREFIX}/bin
	${INSTALL_DATA} -m 644 ${WRKDISTDIR}/analog.cfg \
	  ${PREFIX}/etc/analog.cfg.default
	${TEST} -f ${PREFIX}/etc/analog.cfg || \
	${INSTALL_DATA} -m 644 ${WRKDISTDIR}/analog.cfg \
	  ${PREFIX}/etc/analog.cfg

.include "../../mk/bsd.pkg.mk"
