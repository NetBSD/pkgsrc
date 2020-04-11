# $NetBSD: Makefile,v 1.22 2020/04/11 06:33:47 gutteridge Exp $

.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mate-session-manager-${VERSION:R}.0
CATEGORIES=	x11

COMMENT=	MATE session manager

TOOL_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto
TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
TOOL_DEPENDS+=	autoconf-archive-[0-9]*:../../devel/autoconf-archive
TOOL_DEPENDS+=	mate-common-${VERSION}:../../devel/mate-common

DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

USE_TOOLS+=	autoreconf automake autoconf aclocal libtoolize

.include "../../graphics/MesaLib/features.mk"
CONFIGURE_ARGS+=	--with-glesv2=${MESALIB_SUPPORTS_GLESv2}
PLIST_VARS+=	glesv2
.if ${MESALIB_SUPPORTS_GLESv2} == "yes"
PLIST.glesv2=	yes
.endif

pre-configure:
	cd ${WRKSRC} && autoreconf -vi

.include "options.mk"

.include "../../devel/glib2/schemas.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/xtrans/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
