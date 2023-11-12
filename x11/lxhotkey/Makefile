# $NetBSD: Makefile,v 1.6 2023/11/12 13:24:15 wiz Exp $

DISTNAME=	lxhotkey-0.1.1
PKGREVISION=	5
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lxde/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.lxde.org/
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
