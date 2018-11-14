# $NetBSD: Makefile,v 1.12 2018/11/14 22:22:47 kleink Exp $

PKGREVISION= 2
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mate-terminal-${VERSION}
CATEGORIES=	x11

COMMENT=	MATE terminal emulator application

TOOL_DEPENDS+=	itstool-[0-9]*:../../textproc/itstool
TOOL_DEPENDS+=	libxml2-[0-9]*:../../textproc/libxml2 # for xmllint

.include "options.mk"

.include "../../devel/glib2/schemas.mk"

REPLACE_PERL+=	mate-terminal.wrapper

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/mate-desktop/buildlink3.mk"
.include "../../x11/vte3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
