# $NetBSD: Makefile,v 1.47 2025/08/30 22:46:43 wiz Exp $

PKGREVISION= 10
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mate-terminal-${VERSION:R}.1
CATEGORIES=	x11

USE_TOOLS+=	perl:run

COMMENT=	MATE terminal emulator application

TOOL_DEPENDS+=	libxml2-[0-9]*:../../textproc/libxml2 # for xmllint

.include "options.mk"

.include "../../devel/glib2/schemas.mk"

REPLACE_PERL+=	mate-terminal.wrapper

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/mate-desktop/buildlink3.mk"
.include "../../x11/vte3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
