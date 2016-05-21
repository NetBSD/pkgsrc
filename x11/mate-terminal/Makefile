# $NetBSD: Makefile,v 1.1 2016/05/21 19:16:49 youri Exp $

.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mate-terminal-${MATE_VERSION}
CATEGORIES=	x11

COMMENT=	MATE terminal emulator application

TOOL_DEPENDS+=	itstool-[0-9]*:../../textproc/itstool
TOOL_DEPENDS+=	libxml2-[0-9]*:../../textproc/libxml2 # for xmllint

.include "options.mk"

.include "../../devel/glib2/schemas.mk"

REPLACE_PERL+=	mate-terminal.wrapper

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/mate-desktop/buildlink3.mk"
.include "../../devel/dconf/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/vte/buildlink3.mk"
.if !empty(PKG_BUILD_OPTIONS.gtk2:Mx11)
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.endif
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
