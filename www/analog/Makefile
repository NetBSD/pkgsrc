# $NetBSD: Makefile,v 1.62 2016/01/22 08:33:09 zafer Exp $

DISTNAME=	analog-6.0
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	${HOMEPAGE} \
		http://www.web42.com/analog/

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
	${INSTALL_PROGRAM} ${WRKDISTDIR}/analog ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKDISTDIR}/analog.man ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/analog.1
	${INSTALL_DATA} ${WRKDISTDIR}/docs/* ${DESTDIR}${PREFIX}/share/doc/analog
	${INSTALL_DATA} ${WRKDISTDIR}/images/* ${DESTDIR}${PREFIX}/lib/analog/images
	${INSTALL_DATA} ${WRKDISTDIR}/lang/* ${DESTDIR}${PREFIX}/lib/analog/lang
	${INSTALL_DATA} -m 644 ${WRKDISTDIR}/analog.cfg \
		${DESTDIR}${PREFIX}/share/examples/analog.cfg

.include "../../mk/bsd.pkg.mk"
