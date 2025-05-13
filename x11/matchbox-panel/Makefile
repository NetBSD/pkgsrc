# $NetBSD: Makefile,v 1.39 2025/05/13 11:27:23 nia Exp $
#

DISTNAME=		matchbox-panel-0.9.2
PKGREVISION=		16
CATEGORIES=		x11
MASTER_SITES=		http://matchbox-project.org/sources/matchbox-panel/0.9/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://matchbox-project.org/
COMMENT=		Panel for Matchbox

BROKEN_GETTEXT_DETECTION=	yes

USE_TOOLS+=		gmake msgfmt pkg-config
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--enable-small-icons
CONFIGURE_ARGS+=	--enable-startup-notification
CONFIGURE_ARGS+=	--enable-nls

CFLAGS.SunOS+=		-Du_int64_t=uint64_t

MAKE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR}

.include "../../mk/bsd.prefs.mk"

PLIST_VARS=		apm
.if exists(/usr/include/apm.h) || exists(/usr/include/machine/apmvar.h)
PLIST.apm=		yes
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libmatchbox/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
