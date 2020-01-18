# $NetBSD: Makefile,v 1.18.6.1 2020/01/18 22:05:53 bsiegert Exp $

PKGREVISION= 3
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mate-terminal-${VERSION:R}.1
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
