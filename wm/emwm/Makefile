# $NetBSD: Makefile,v 1.8 2024/12/08 16:34:38 vins Exp $

DISTNAME=	emwm-src-1.2
PKGNAME=	${DISTNAME:S,-src,,}
PKGREVISION=	2
CATEGORIES=	wm
MASTER_SITES=	https://fastestcode.org/dl/
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	.tar.xz
DISTFILES+=	${DEFAULT_DISTFILES} app-icons.tar.xz	\
		gtk-configs.tar.xz Xresources-sample
SITES.Xresources-sample=	${MASTER_SITES:S/dl/misc/}

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://fastestcode.org/emwm.html
COMMENT=	Enhanced Motif Window Manager
LICENSE=	gnu-lgpl-v2.1 AND cc-by-sa-v3.0

USE_BSD_MAKEFILE=	yes

RCDIR=		${PREFIX}/lib/X11
EGDIR=		share/examples/${PKGBASE}
EGFILES=	gtk-configs/* Xresources-sample

SUBST_CLASSES+=		pkgsrc
SUBST_STAGE.pkgsrc=	pre-configure
SUBST_FILES.pkgsrc=	mf/Makefile.pkgsrc
SUBST_VARS.pkgsrc=	CC CFLAGS LDFLAGS
SUBST_VARS.pkgsrc+=	PREFIX PKGMANDIR RCDIR
SUBST_MESSAGE.pkgsrc=	Replacing pkgsrc placeholders

MAKE_FLAGS+=	CC=${CC:Q}
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}

INSTALLATION_DIRS+=	${EGDIR} share/pixmaps

post-install:
	${INSTALL_DATA} ${EGFILES:S|^|${WRKDIR}/|}	\
		${DESTDIR}${PREFIX}/${EGDIR}
	${INSTALL_DATA} ${WRKDIR}/icons/*.xpm		\
		${DESTDIR}${PREFIX}/share/pixmaps

.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
