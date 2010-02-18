# $NetBSD: Makefile,v 1.2 2010/02/18 12:03:23 obache Exp $
#

DISTNAME=	scrotwm-0.9.22
CATEGORIES=	wm
MASTER_SITES=	http://scrotwm.org/snapshot/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.scrotwm.org/
COMMENT=	Small dynamic tiling window manager for X11

DEPENDS+=	dmenu-[0-9]*:../../x11/dmenu

BUILDLINK_TRANSFORM+=	rm:-Werror
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "OpenBSD"
USE_BSD_MAKEFILE=	yes
INSTALLATION_DIRS+=	bin lib ${PKGMANDIR}/man1
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=	MANINSTALL=maninstall
# sync with major.minor from ${WRKSRC}/lib/shlib_version.
CFLAGS+=	-DSWM_LIB=\"${PREFIX}/lib/libswmhack.so.0.0\"
.else
USE_TOOLS+=	gmake
CFLAGS+=	-I${X11BASE}/include
LDFLAGS+=	-L${X11BASE}/lib ${COMPILER_RPATH_FLAG}${X11BASE}/lib
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}
.  if ${OPSYS} == "Darwin"
BUILD_DIRS=	osx
.  else
BUILD_DIRS=	linux
.  endif
.endif

INSTALLATION_DIRS+=	share/examples/scrotwm

post-install:
	${INSTALL_DATA} ${WRKSRC}/*.conf ${DESTDIR}${PREFIX}/share/examples/scrotwm
	${INSTALL_DATA} ${WRKSRC}/*.sh ${DESTDIR}${PREFIX}/share/examples/scrotwm

.include "../../x11/libX11/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXt=	build
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
