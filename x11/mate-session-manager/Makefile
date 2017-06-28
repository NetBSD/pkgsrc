# $NetBSD: Makefile,v 1.6 2017/06/28 16:05:43 jperkin Exp $

.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mate-session-manager-${VERSION}
CATEGORIES=	x11

COMMENT=	MATE session manager

TOOL_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto
TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

.include "options.mk"

.include "../../devel/glib2/schemas.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/xtrans/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
