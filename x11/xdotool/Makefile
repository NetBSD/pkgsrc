# $NetBSD: Makefile,v 1.7 2024/04/06 08:07:15 wiz Exp $

DISTNAME=	xdotool-3.20211022.1
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=jordansissel/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	rga@sdf.lonestar.org
HOMEPAGE=	https://www.semicomplete.com/projects/xdotool/
COMMENT=	Simulate keyboard input and mouse activity using X11 xtest extension
LICENSE=	modified-bsd

# XXX: The -rpath fix leads to `gcc: Missing argument for -Wl,-rpath'
# XXX: and build failure.
MAKE_ENV+=	WITHOUT_RPATH_FIX=1

USE_TOOLS+=	gmake pod2man pkg-config

USE_LANGUAGES=	c99

SUBST_CLASSES+=			fix-getopt
SUBST_STAGE.fix-getopt=		pre-build
SUBST_MESSAGE.fix-getopt=	Fixing getopt
SUBST_FILES.fix-getopt=		*.c
SUBST_SED.fix-getopt+=		-e 's,getopt_long_only,getopt_long,g'

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
