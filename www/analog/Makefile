# $NetBSD: Makefile,v 1.57 2008/05/25 14:45:18 tron Exp $

DISTNAME=	analog-6.0
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${HOMEPAGE} \
		http://www.web42.com/analog/ \
		http://analog.org/loganalysis/ \
		http://www.gekko.de/analog/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.analog.cx/
COMMENT=	Extremely fast program for analysing WWW logfiles

WRKSRC=		${WRKDISTDIR}/src
BUILD_TARGET=	analog
MAKE_ENV+=	PREFIX=${PREFIX:Q} SYSCONFDIR=${PKG_SYSCONFDIR:Q}
WRKDISTDIR=	${WRKDIR}/${DISTNAME}

EGDIR=		${PREFIX}/share/examples
CONF_FILES=	${EGDIR}/analog.cfg ${PKG_SYSCONFDIR}/analog.cfg

.if !exists(/usr/include/glob.h)
CFLAGS+=	-DNOGLOB
.endif

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 lib/analog/lang lib/analog/images
INSTALLATION_DIRS+=	share/doc/analog share/examples

LIBS+=		-lm
LIBS.SunOS+=	-lnsl -lsocket
MAKE_ENV+=	LIBS=${LIBS:M*:Q}

do-install:
	${INSTALL_PROGRAM} ${WRKDISTDIR}/analog ${PREFIX}/bin
	${INSTALL_DATA} ${WRKDISTDIR}/analog.man ${PREFIX}/${PKGMANDIR}/man1/analog.1
	${INSTALL_DATA} ${WRKDISTDIR}/docs/* ${PREFIX}/share/doc/analog
	${INSTALL_DATA} ${WRKDISTDIR}/images/* ${PREFIX}/lib/analog/images
	${INSTALL_DATA} ${WRKDISTDIR}/lang/* ${PREFIX}/lib/analog/lang
	${INSTALL_DATA} -m 644 ${WRKDISTDIR}/analog.cfg \
		${PREFIX}/share/examples/analog.cfg

.include "../../mk/bsd.pkg.mk"
