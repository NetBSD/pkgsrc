# $NetBSD: Makefile,v 1.6 2014/02/16 15:54:09 wiedi Exp $

DISTNAME=	xtide-2.8.3
PKGREVISION=	5
CATEGORIES=	misc x11
MASTER_SITES=	ftp://ftp.flaterco.com/xtide/
DISTFILES=	${DISTNAME}.tar.bz2 ${HARMONICS_FILE}.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.flaterco.com/
COMMENT=	X11 tide predictor

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

PREV_PKGPATH=	misc/xtide

HARMONICS_FILE=	harmonics-dwf-20060708.tcd

CONFIGURE_ARGS+=--sysconfdir=${PKG_SYSCONFDIR:Q} X11BASE=${X11BASE:Q}
EGDIR=		${PREFIX}/share/examples/xtide
CONF_FILES=	${EGDIR}/xtide.conf ${PKG_SYSCONFDIR}/xtide.conf

LDFLAGS.SunOS+=	-lsocket -lnsl

SUBST_CLASSES+=	xt
SUBST_STAGE.xt=	pre-configure
SUBST_FILES.xt=	DOCUMENTATION/*
SUBST_SED.xt=	-e 's|/usr/local|${PREFIX}|g'

PLIST_SUBST+=	HARMONICS_FILE=${HARMONICS_FILE:Q}

INSTALLATION_DIRS=	share/xtide ${EGDIR}
INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX} \
			mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

post-extract:
	${ECHO} "${PREFIX}/share/xtide/${HARMONICS_FILE}" > ${WRKDIR}/xtide.conf

post-install:
	${INSTALL_DATA} ${WRKDIR}/xtide.conf ${DESTDIR}${EGDIR}/xtide.conf
	${INSTALL_DATA} ${WRKDIR}/${HARMONICS_FILE} ${DESTDIR}${PREFIX}/share/xtide

.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
