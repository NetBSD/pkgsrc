# $NetBSD: Makefile,v 1.10 2018/11/14 22:22:34 kleink Exp $

PKGREVISION=	8
DISTNAME=	trayer-1.1.6
CATEGORIES=	wm x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=sargon/}
GITHUB_PROJECT=	trayer-srg
GITHUB_TAG=	${PKGNAME_NOREV}

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://github.com/sargon/trayer-srg
COMMENT=	Lightweight GTK2-based systray for UNIX desktop
LICENSE=	mit

USE_TOOLS+=	gmake pkg-config

BUILD_MAKE_FLAGS=	CFLAGS=${CFLAGS:Q}
INSTALL_MAKE_FLAGS=	PREFIX=${DESTDIR}${PREFIX}

SUBST_CLASSES+=		paths
SUBST_SED.paths=	-e 's,/usr,${PREFIX},'
SUBST_FILES.paths=	config.h Makefile.config
SUBST_STAGE.paths=	pre-build
SUBST_MESSAGE.paths=	Fixing path to ${PREFIX}.

AUTO_MKDIRS=		yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/trayer/

.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2-xlib/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
