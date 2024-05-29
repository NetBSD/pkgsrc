# $NetBSD: Makefile,v 1.16 2024/05/29 16:35:18 adam Exp $

DISTNAME=	yad-10.1
PKGREVISION=	15
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=v1cont/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/v1cont/yad
COMMENT=	Display GTK+ dialog boxes from the command line
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	perl bash:run pkg-config gmake
USE_TOOLS+=	intltool msgfmt msgmerge xgettext

ALL_ENV+=	BASH=${BASH}

TOOL_DEPENDS+=	p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser

GNU_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD" && ${X11_TYPE} == "native"
CONFIGURE_ARGS+=	--with-rgb=${X11BASE}/lib/X11/rgb.txt
.else
DEPENDS+=		rgb-[0-9]*:../../x11/rgb
CONFIGURE_ARGS+=	--with-rgb=${PREFIX}/share/X11/rgb.txt
.endif

.include "../../devel/glib2/schemas.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../textproc/gspell/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/gtksourceview3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
