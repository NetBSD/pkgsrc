# $NetBSD: Makefile,v 1.14 2023/11/12 13:23:46 wiz Exp $

DISTNAME=	coma-1.1
PKGREVISION=	5
CATEGORIES=	wm
MASTER_SITES=	https://coma.one/releases/

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://coma.one/wm/
COMMENT=	Keyboard driven tiling window manager
LICENSE=	isc

USE_LANGUAGES=	c99

REPLACE_INTERPRETER+=	sh
REPLACE.sh.old=		.*/bin/zsh
REPLACE.sh.new=		${SH:Q}
REPLACE_FILES.sh+=	scripts/coma-cmd
REPLACE_FILES.sh+=	scripts/coma-remote

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
SUBST_CLASSES+=		ints
SUBST_MESSAGE.ints=	SunOS stdint(3) doesn't provide `u_int*' typedefs
SUBST_STAGE.ints=	pre-configure
SUBST_FILES.ints+=	client.c coma.h frame.c wm.c
SUBST_SED.ints=		-e 's|u_int|uint|g'
.endif

LDFLAGS+=	${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libX11}/lib
LDFLAGS+=	-L${BUILDLINK_PREFIX.libX11}/lib -lX11 -lXft

MAKE_FLAGS+=	CC=${CC:Q}
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}
MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}
MAKE_FLAGS+=	MAN_DIR=${DESTDIR}${PREFIX}/${PKGMANDIR}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Linux"
.  include "../../devel/libbsd/buildlink3.mk"
.endif
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
