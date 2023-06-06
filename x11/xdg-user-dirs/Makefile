# $NetBSD: Makefile,v 1.14 2023/06/06 12:42:55 riastradh Exp $

DISTNAME=	xdg-user-dirs-0.18
CATEGORIES=	x11
MASTER_SITES=	http://user-dirs.freedesktop.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.freedesktop.org/wiki/Software/xdg-user-dirs
COMMENT=	Tool to manage "well known" user directories
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
TOOL_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt

EGDIR=		${PREFIX}/share/examples/xdg
MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/autostart

CONF_FILES+=	${EGDIR}/user-dirs.conf \
		${PKG_SYSCONFDIR}/xdg/user-dirs.conf
CONF_FILES+=	${EGDIR}/user-dirs.defaults \
		${PKG_SYSCONFDIR}/xdg/user-dirs.defaults
CONF_FILES+=	${EGDIR}/autostart/xdg-user-dirs.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/xdg-user-dirs.desktop

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
