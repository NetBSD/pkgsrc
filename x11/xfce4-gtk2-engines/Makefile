# $NetBSD: Makefile,v 1.10 2004/03/10 11:53:37 xtraeme Exp $
#

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	2.1.9

DISTNAME=	gtk-xfce-engine-${XFCE4_VERSION}
PKGNAME=	xfce4-gtk2-engine-${XFCE4_VERSION}
CATEGORIES=	x11
COMMENT=	XFce4 GTK2 themes

DEPENDS+=	xdg-dirs>=1.1:../../misc/xdg-dirs

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
