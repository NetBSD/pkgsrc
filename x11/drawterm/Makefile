# $NetBSD: Makefile,v 1.5 2022/12/18 17:43:28 vins Exp $

DISTNAME=	snap
PKGVER=		20221013
PKGNAME=	drawterm-${PKGVER}
CATEGORIES=	x11 plan9
DIST_SUBDIR=	${PKGNAME_NOREV}
MASTER_SITES=	https://git.9front.org/git/plan9front/drawterm/65e8a26e1dac4a0f589f615126ad87a92c9c11ab/

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://drawterm.9front.org/
COMMENT=	Utility to connect to Plan9 CPU servers
LICENSE=	mit

USE_LANGUAGES=	c c99

MAKE_FLAGS+=	CC=${CC:Q}
MAKE_FLAGS+=	X11=${X11BASE}
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}
MAKE_FLAGS+=	RANLIB=${RANLIB:Q}

.include "../../mk/bsd.prefs.mk"

.if ${PKGSRC_COMPILER:Mgcc}
CFLAGS+=	-Wall -Wno-missing-braces -ggdb
CFLAGS+=	-I${WRKSRC} -I${WRKSRC}/include -I${WRKSRC}/kern
CFLAGS+=	-c -I${X11}/include -D_THREAD_SAFE ${PTHREAD} -O2
LDFLAGS+=	${PTHREAD} -lpthread
.else
CFLAGS+=	-I{WRKSRC} -I${WRKSRC}/include -I${WRKSRC}/kern
CFLAGS+=	-g -c -I${X11}/include -D_THREAD_SAFE -O2
LDFLAGS+=	-lpthread
.endif

.if ${OPSYS:M*BSD}
MAKE_FLAGS+=	CONF=${LOWER_OPSYS}
.  if ${OPSYS} == "OpenBSD"
LD_ADD=		"-lX11 -lXt -ggdb -lsndio"
.  elif ${OPSYS} == "NetBSD"
LD_ADD=		"-lX11 -lXt -ggdb -lossaudio"
.  else
LD_ADD=		"-lX11 -lXt -ggdb"
.  endif

.elif ${OPSYS} == "Linux"
.include "../../audio/alsa-lib/buildlink3.mk"
MAKE_FLAGS+=	CONF=unix
MAKE_FLAGS+=	AUDIO=alsa
LD_ADD=		"-lX11 -lXt -ggdb -lm -lasound"

.elif ${OPSYS} == "Darwin"
MAKE_FLAGS+=	CONF=osx-x11
MAKE_FLAGS+=	PTHREAD=''
LD_ADD=		"-lX11 -lXt -ggdb"

.elif ${OPSYS} == "IRIX" && !empty(PKGSRC_COMPILER:Mmipspro*)
MAKE_FLAGS+=	CONF=irix
MAKE_FLAGS+=	CFLAGS+=-DIRIX
LD_ADD=		"-lX11 -lXt -g -lpthread"
.endif

.if ${OPSYS} == "SunOS"
SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths+=	Make.unix
SUBST_SED.paths=	-e 's,i.86/386,i86pc/amd64,'

LD_ADD=		"-lX11 -lXt -lrt -lpthread -lsocket -lnsl"

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

.if defined(LD_ADD)
MAKE_FLAGS+=	LDADD=${LD_ADD}
.endif

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

WRKSRC=	${WRKDIR}/drawterm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/drawterm ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/drawterm.1 					\
	${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
