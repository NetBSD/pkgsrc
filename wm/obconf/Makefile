# $NetBSD: Makefile,v 1.55 2020/03/10 22:11:07 wiz Exp $

DISTNAME=		obconf-2.0.4
PKGREVISION=		12
CATEGORIES=		wm
MASTER_SITES=		http://openbox.org/dist/obconf/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://openbox.org/wiki/ObConf:About
COMMENT=		Tool for configuring the Openbox window manager
LICENSE=		gnu-gpl-v2

USE_TOOLS+=		pkg-config gzip gunzip
GNU_CONFIGURE=		YES

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Linux"
USE_TOOLS+=		gtar:run
CONFIGURE_ENV+=	ac_cv_prog_TAR=${GTAR:Q}
.else
USE_TOOLS+=		tar:run
CONFIGURE_ENV+=	ac_cv_prog_TAR=${TAR:Q}
.endif

.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
BUILDLINK_API_DEPENDS.openbox+=	openbox>=3.5.2
.include "../../wm/openbox/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
