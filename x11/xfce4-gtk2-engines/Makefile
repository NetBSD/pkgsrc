# $NetBSD: Makefile,v 1.9 2004/03/10 07:41:16 martti Exp $
#

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	2.1.9

DISTNAME=	gtk-xfce-engine-${XFCE4_VERSION}
PKGNAME=	xfce4-gtk2-engine-${XFCE4_VERSION}
CATEGORIES=	x11
COMMENT=	XFce4 GTK2 themes

DEPENDS+=	xdg-dirs>=1.1:../../misc/xdg-dirs

.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
