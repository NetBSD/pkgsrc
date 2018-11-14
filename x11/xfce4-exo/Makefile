# $NetBSD: Makefile,v 1.56 2018/11/14 22:22:51 kleink Exp $

PKGREVISION= 3
.include "../../meta-pkgs/xfce4/Makefile.common"

VERSION=	0.12.2
DISTNAME=	exo-${VERSION}
PKGNAME=	xfce4-exo-${VERSION}
CATEGORIES=	x11
MASTER_SITES=	http://archive.xfce.org/src/xfce/exo/0.12/

HOMEPAGE=	http://docs.xfce.org/xfce/exo/start
COMMENT=	Xfce extension library

USE_TOOLS+=	perl:run
REPLACE_PERL=	exo-helper/helpers/exo-compose-mail-1

DEPENDS+=	p5-URI>=0:../../www/p5-URI

PKGCONFIG_OVERRIDE+=	exo/exo-1.pc.in

PKG_SYSCONFSUBDIR=	xdg/xfce4
EGDIR=			${XFCE4_EGBASE}

CONF_FILES=		${EGDIR}/helpers.rc ${PKG_SYSCONFDIR}/helpers.rc
OWN_DIRS+=		${EGDIR}

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libxfce4ui/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
