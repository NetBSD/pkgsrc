# $NetBSD: Makefile,v 1.29 2010/02/01 14:11:38 tnn Exp $

DISTNAME=		obconf-2.0.3
PKGREVISION=		2
DIST_SUBDIR=		obconf-2.0.3
CATEGORIES=		wm
MASTER_SITES=		http://icculus.org/openbox/obconf/
# PR pkg/36489
MASTER_SITES+=		http://offload1.icculus.org/openbox/obconf/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://icculus.org/openbox/index.php/ObConf:About
COMMENT=		Tool for configuring the Openbox window manager

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		YES

.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/buildlink3.mk"
BUILDLINK_API_DEPENDS.openbox+=	openbox>=3.4.3
.include "../../wm/openbox/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
