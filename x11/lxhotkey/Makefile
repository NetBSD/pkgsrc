# $NetBSD: Makefile,v 1.18 2026/09/27 11:39:26 tnn Exp $

DISTNAME=	lxhotkey-0.1.1
PKGREVISION=	16
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lxde/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxde/lxhotkey
COMMENT=	View and change global keyboard shortcuts for window manager actions
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake intltool pkg-config msgfmt msgmerge xgettext

CONFIGURE_ARGS+=	--with-gtk=2

.include "../../sysutils/libfm/buildlink3.mk"
.include "../../sysutils/libfm-extra/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
