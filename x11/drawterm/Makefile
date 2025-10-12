# $NetBSD: Makefile,v 1.11 2025/10/12 13:42:33 vins Exp $

DISTNAME=	snap
PKGNAME=	drawterm-20240703
PKGREVISION=	2
SNAPSHOT=	f11139d4c918802a87730bc14d094670ee4ce572
CATEGORIES=	x11 plan9
MASTER_SITES=	https://git.9front.org/git/plan9front/drawterm/${SNAPSHOT}/
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://drawterm.9front.org/
COMMENT=	Utility to connect to Plan9 CPU servers
LICENSE=	mit

USE_TOOLS+=	sed

PTHREAD_AUTO_VARS=	yes
PTHREAD_OPTS=		require

MAKE_FLAGS+=	CONF=pkgsrc CC=${CC:Q} X11=${X11BASE} \
		RANLIB=${RANLIB:Q} LDADD=${LIBS:Q} \
		PTHREAD=${PTHREAD_CFLAGS:Q}

CFLAGS.SunOS+=	-D__EXTENSIONS__

LIBS+=		-lX11 -lXt -lm
LIBS.OpenBSD+=	-lsndio
LIBS.NetBSD+=	-lossaudio
LIBS.Linux+=	-lasound
LIBS.SunOS+=	-lrt -lsocket -lnsl

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS:M*BSD} || ${OPSYS} == "SunOS"
.include "../../mk/oss.buildlink3.mk"
MAKE_FLAGS+=    AUDIO=unix
.elif ${OPSYS} == "Linux"
.include "../../audio/alsa-lib/buildlink3.mk"
MAKE_FLAGS+=	AUDIO=alsa
.endif

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

WRKSRC=	${WRKDIR}/drawterm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/drawterm		\
		${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/drawterm.1		\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
