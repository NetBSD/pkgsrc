# $NetBSD: Makefile,v 1.9 2011/11/01 06:02:39 sbd Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.2.1

DISTNAME=	xfce4-dict-plugin-${XFCE4_VERSION}
PKGREVISION=	7
CATEGORIES=	textproc
MASTER_SITES=	http://goodies.xfce.org/releases/xfce4-dict-plugin/
COMMENT=	Xfce dictionary server plugin

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
