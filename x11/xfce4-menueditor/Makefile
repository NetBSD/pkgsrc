# $NetBSD: Makefile,v 1.3 2004/03/10 11:59:31 xtraeme Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	1.0rc3

DISTNAME=	xfce4-menueditor-${XFCE4_VERSION}
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://users.skynet.be/p0llux/files/
COMMENT=	XFce4 menu editor

EXTRACT_SUFX=	.tar.bz2
WRKSRC=		${WRKDIR}/xfce4-menueditor

CONFIGURE_ARGS+=--disable-cvs

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/libxfce4gui/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
