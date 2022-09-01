# $NetBSD: Makefile,v 1.33 2022/09/01 01:23:10 gutteridge Exp $

.include "../../meta-pkgs/mate/Makefile.common"

VERSION=	1.26.0
DISTNAME=	mate-terminal-${VERSION}
CATEGORIES=	x11
MASTER_SITES+=  https://pub.mate-desktop.org/releases/${VERSION:R}/

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
