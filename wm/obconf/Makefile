# $NetBSD: Makefile,v 1.39 2012/03/03 00:14:03 wiz Exp $

DISTNAME=		obconf-2.0.3
PKGREVISION=		11
DIST_SUBDIR=		obconf-2.0.3.orig
CATEGORIES=		wm
MASTER_SITES=		http://openbox.org/dist/obconf/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://openbox.org/wiki/ObConf:About
COMMENT=		Tool for configuring the Openbox window manager

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config gtar
GNU_CONFIGURE=		YES

.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
BUILDLINK_API_DEPENDS.openbox+=	openbox>=3.4.3
.include "../../wm/openbox/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
