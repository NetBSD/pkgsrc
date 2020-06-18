# $NetBSD: Makefile,v 1.15 2020/06/18 18:45:25 pin Exp $

DISTNAME=	spectrwm-3.4.0
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=conformal/}
GITHUB_TAG=	${GITHUB_PROJECT:tu}_${PKGVERSION_NOREV:S/./_/g}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/conformal/spectrwm
COMMENT=	Small dynamic tiling window manager for X11
LICENSE=	isc

DEPENDS+=	dmenu-[0-9]*:../../x11/dmenu

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "OpenBSD"
USE_BSD_MAKEFILE=	yes
INSTALLATION_DIRS+=	bin lib ${PKGMANDIR}/man1
MAKE_FLAGS+=		MANDIR=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=		MANINSTALL=maninstall
# sync with major.minor from ${WRKSRC}/lib/shlib_version.
CFLAGS+=		-DSWM_LIB=\"${PREFIX}/lib/libswmhack.so.0.0\"
.else
CFLAGS+=		-I${PREFIX}/include
LDFLAGS+=		-L${PREFIX}/lib ${COMPILER_RPATH_FLAG}${PREFIX}/lib
MAKE_FLAGS+=		MANDIR=${PREFIX}/${PKGMANDIR}
.  if ${OPSYS} == "Darwin"
USE_TOOLS+=		gmake
BUILD_DIRS=		osx
.  elif ${OPSYS} == "FreeBSD"
BUILD_DIRS=		freebsd
.  elif ${OPSYS} == "NetBSD"
BUILD_DIRS=		netbsd
.  else
USE_TOOLS+=		gmake
BUILD_DIRS=		linux
.  endif
.endif

INSTALLATION_DIRS+=	share/examples/spectrwm

post-extract:
	${RUN} cd ${WRKSRC} && ${CP} -R freebsd netbsd

post-install:
	${INSTALL_DATA} ${WRKSRC}/*.conf ${DESTDIR}${PREFIX}/share/examples/spectrwm
	${INSTALL_DATA} ${WRKSRC}/*.sh ${DESTDIR}${PREFIX}/share/examples/spectrwm

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXt=	build
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/xcb-util-keysyms/buildlink3.mk"
.include "../../x11/xcb-util-wm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
