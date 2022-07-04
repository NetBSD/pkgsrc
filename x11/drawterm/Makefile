# $NetBSD: Makefile,v 1.2 2022/07/04 21:52:04 gutteridge Exp $

DISTNAME=	snap
BUILD=		20220603
PKGNAME=	drawterm-${BUILD}
CATEGORIES=	x11 plan9
DIST_SUBDIR=	${PKGNAME_NOREV}-${BUILD}
MASTER_SITES=	https://git.9front.org/git/plan9front/drawterm/bee4db6507fdf31bddfa98d26a673e135dfd28ad/

MAINTAINER=	vms@retrobsd.ddns.net
HOMEPAGE=	https://drawterm.9front.org/
COMMENT=	Utility to connect to Plan9 CPU servers
LICENSE=	mit

USE_LANGUAGES=	c c99

MAKEFLAGS+=	X11=${X11BASE} CFLAGS=${CFLAGS:Q}
MAKEFLAGS+=	LDFLAGS=${LDFLAGS:Q}

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
MAKEFLAGS+=		CONF=${LOWER_OPSYS}
.  if ${OPSYS} == OpenBSD
MAKEFLAGS+=		CC?=cc
.  elif ${OPSYS} == FreeBSD
MAKEFLAGS+=		CC?=clang
.  endif
.endif

.if ${OPSYS} == "Linux"
.include "../../audio/alsa-lib/buildlink3.mk"
MAKEFLAGS+=	CONF=unix AUDIO=alsa
LD_ADD=	"-L${X11}/lib64 -L${X11}/lib -lX11 -ggdb -lm -lasound"

.elif ${OPSYS} == "Darwin"
MAKEFLAGS+=	CONF=osx-x11 CC?=clang PTHREAD=''
LD_ADD=		"-L${X11}/lib -lX11 -ggdb"

.elif ${OPSYS} == "IRIX" && !empty(PKGSRC_COMPILER:Mmipspro*)
MAKEFLAGS+=	CONF=irix CFLAGS+=-DIRIX
.endif

.if ${OPSYS} == "SunOS"
SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths+=	Make.unix
SUBST_SED.paths=	-e 's,i.86/386,i86pc/amd64,'

LD_ADD=		"-L${X11}/lib/64 -L${X11}/lib -lX11 \
			-lrt -lpthread -lsocket -lnsl"

.  if ${OPSYS_VERSION} <= 051000
MAKEFLAGS+=	AUDIO=sun
.  else
MAKEFLAGS+=	AUDIO=unix
.  endif

.  if !empty(PKGSRC_COMPILER:Msunpro)
MAKEFLAGS+=	CONF=sun
.  else
MAKEFLAGS+=	CONF=unix
.  endif
.endif

.if defined(LD_ADD)
MAKEFLAGS+=	LDADD=${LD_ADD}
.endif

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

WRKSRC=	${WRKDIR}/drawterm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/drawterm ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/drawterm.1 								\
	${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
