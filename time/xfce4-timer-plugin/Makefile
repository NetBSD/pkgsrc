# $NetBSD: Makefile,v 1.3 2009/08/26 19:56:57 sno Exp $
#

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.5.1

DISTNAME=	xfce4-timer-plugin-${XFCE4_VERSION}
PKGREVISION=	1
CATEGORIES=	time
MASTER_SITES=	http://goodies.xfce.org/releases/xfce4-timer-plugin/
COMMENT=	Xfce4 timer plugin

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
