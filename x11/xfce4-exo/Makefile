# $NetBSD: Makefile,v 1.77 2022/08/11 05:09:34 gutteridge Exp $

PKGREVISION= 2
.include "../../meta-pkgs/xfce4/Makefile.common"

VERSION=	4.16.4
DISTNAME=	exo-${VERSION}
PKGNAME=	xfce4-exo-${VERSION}
CATEGORIES=	x11
MASTER_SITES=	https://archive.xfce.org/src/xfce/exo/${VERSION:R}/

HOMEPAGE=	https://docs.xfce.org/xfce/exo/start
COMMENT=	Xfce extension library

USE_TOOLS+=	perl:run
REPLACE_PERL=	exo-helper/helpers/exo-compose-mail

DEPENDS+=	p5-URI>=0:../../www/p5-URI

PKGCONFIG_OVERRIDE+=	exo/exo-1.pc.in

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libxfce4ui/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
