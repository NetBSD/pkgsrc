# $NetBSD: Makefile,v 1.22 2023/11/12 13:24:15 wiz Exp $

DISTNAME=	lxappearance-0.6.3
PKGREVISION=	11
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lxde/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://lxde.org/
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
