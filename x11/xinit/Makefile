# $NetBSD: Makefile,v 1.7 2008/05/16 13:48:41 tnn Exp $
#

DISTNAME=		xinit-1.0.8
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/app/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X init program

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config xauth:run

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mhp)
CONFIGURE_ENV+=		ac_cv_path_RAWCPP="cc -E -Uunix -"
.endif

.include "../../x11/libX11/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
