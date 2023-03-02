# $NetBSD: Makefile,v 1.6 2023/03/02 12:55:00 vins Exp $

DISTNAME=	snap
PKGVER=		20230224
PKGNAME=	drawterm-${PKGVER}
CATEGORIES=	x11 plan9
DIST_SUBDIR=	${PKGNAME_NOREV}
MASTER_SITES=	https://git.9front.org/git/plan9front/drawterm/ed9cff5a4c39322744c4708699c9ae6651b7c9ab/

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://drawterm.9front.org/
COMMENT=	Utility to connect to Plan9 CPU servers
LICENSE=	mit

PTHREAD_AUTO_VARS=	yes

CFLAGS+=	-I${WRKSRC} -I${WRKSRC}/include -I${WRKSRC}/kern

MAKE_FLAGS+=	CC=${CC:Q}
MAKE_FLAGS+=	X11=${X11BASE}
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}
MAKE_FLAGS+=	LDADD="-lX11 -lXt -lm ${EXTRA_LIBS}"
MAKE_FLAGS+=	RANLIB=${RANLIB:Q}

.include "../../mk/bsd.prefs.mk"

.if ${PKGSRC_COMPILER:Mgcc}
CFLAGS+=	-Wall -Wno-missing-braces -ggdb -c
.else
CFLAGS+=	-g -c
.endif

.if ${OPSYS:M*BSD}
MAKE_FLAGS+=	CONF=${LOWER_OPSYS}
.  if ${OPSYS} == "OpenBSD"
EXTRA_LIBS=	-lsndio
.  elif ${OPSYS} == "NetBSD"
EXTRA_LIBS=	-lossaudio
.  endif

.elif ${OPSYS} == "Linux"
.include "../../audio/alsa-lib/buildlink3.mk"
MAKE_FLAGS+=	CONF=unix
MAKE_FLAGS+=	AUDIO=alsa
EXTRA_LIBS=	-lasound

.elif ${OPSYS} == "Darwin"
MAKE_FLAGS+=	CONF=osx-x11

.elif ${OPSYS} == "IRIX" && !empty(PKGSRC_COMPILER:Mmipspro*)
MAKE_FLAGS+=	CONF=irix
MAKE_FLAGS+=	CFLAGS+=-DIRIX
.endif

.if ${OPSYS} == "SunOS"
SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths+=	Make.unix
SUBST_SED.paths=	-e 's,i.86/386,i86pc/amd64,'

EXTRA_LIBS=		-lrt -lsocket -lnsl

.  if ${OPSYS_VERSION} <= 051000
MAKE_FLAGS+=	AUDIO=sun
.  else
MAKE_FLAGS+=	AUDIO=unix
.  endif

.  if !empty(PKGSRC_COMPILER:Msunpro)
MAKE_FLAGS+=	CONF=sun
.  else
MAKE_FLAGS+=	CONF=unix
.  endif
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
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
