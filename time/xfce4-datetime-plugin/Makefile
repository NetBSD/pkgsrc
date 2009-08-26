# $NetBSD: Makefile,v 1.16 2009/08/26 19:57:04 sno Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.5.0

DISTNAME=	xfce4-datetime-plugin-${XFCE4_VERSION}
#PKGREVISION=	1
PKGREVISION=	1
CATEGORIES=	time
MASTER_SITES=	http://goodies.xfce.org/releases/xfce4-datetime-plugin/
EXTRACT_SUFX=	.tar.gz
COMMENT=	Xfce calendar plugin

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
