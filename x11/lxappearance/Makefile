# $NetBSD: Makefile,v 1.34 2026/09/27 11:39:26 tnn Exp $

DISTNAME=	lxappearance-0.6.3
PKGREVISION=	22
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lxde/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://github.com/lxde/lxappearance
COMMENT=	GTK+ theme switcher

LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	XSLTPROC=${PREFIX}/bin/xsltproc
CONFIGURE_ARGS+=	--enable-dbus
USE_LIBTOOL=		yes
USE_TOOLS+=		intltool pkg-config msgfmt

TOOL_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl
TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
