# $NetBSD: Makefile,v 1.35 2023/01/03 17:38:32 wiz Exp $

PKGREVISION= 1
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mate-terminal-${VERSION}
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
