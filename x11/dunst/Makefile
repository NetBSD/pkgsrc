# $NetBSD: Makefile,v 1.13 2018/11/14 22:22:39 kleink Exp $

DISTNAME=	dunst-1.2.0
PKGREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=dunst-project/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dunst-project.org/
COMMENT=	Customizable and lightweight notification-daemon
LICENSE=	modified-bsd

USE_TOOLS+=	gmake pkg-config

MAKE_FLAGS+=	MANPREFIX=${PREFIX}/${PKGMANDIR}

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		dunstrc config.h
SUBST_SED.fix-paths+=		-e 's,/usr/bin,${PREFIX}/bin,g'
SUBST_SED.fix-paths+=		-e 's,/usr/share,${PREFIX}/share,g'

.include "../../devel/pango/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../x11/libxdg-basedir/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
