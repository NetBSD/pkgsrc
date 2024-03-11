# $NetBSD: Makefile,v 1.13 2024/03/11 14:01:13 vins Exp $

DISTNAME=	sdorfehs-1.5
PKGREVISION=	3
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=jcs/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jcs/sdorfehs/
COMMENT=	Tiling window manager descended from ratpoison
LICENSE=	gnu-gpl-v2

LIBS.SunOS+=	-lsocket

MAKE_ENV+=	CC=${CC:Q}
MAKE_ENV+=	CFLAGS=${CFLAGS:Q}
MAKE_ENV+=	LDFLAGS=${LDFLAGS:Q}
MAKE_ENV+=	LIBS=${LIBS:Q}

SUBST_CLASSES+=		prefix
SUBST_MESSAGE.prefix=	Fixing paths.
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix+=	Makefile
SUBST_VARS.prefix=	CC PKGMANDIR PREFIX

INSTALLATION_DIRS=	bin/ ${PKGMANDIR}/man1/

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXres/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
