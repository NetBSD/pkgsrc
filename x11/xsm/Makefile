# $NetBSD: Makefile,v 1.3 2008/05/17 20:51:31 tnn Exp $
#

DISTNAME=		xsm-1.0.1
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/app/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X Session Manager

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

CONFIGURE_ENV+=		APP_MAN_SUFFIX=1

.include "../../mk/bsd.prefs.mk"

# Most modern Linuxen don't come with rcmds by default,
# so just pretend to have them to keep configure happy.
.if !exists(/usr/bin/rsh)
CONFIGURE_ENV+=		ac_cv_path_RSH=/usr/bin/rsh
.endif

.include "../../x11/libXaw/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
