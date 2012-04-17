# $NetBSD: Makefile,v 1.15 2012/04/17 17:52:29 joerg Exp $
#

DISTNAME=		xinit-1.2.1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X init program
LICENSE=		mit

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-xinit=${PREFIX}/bin/xinit
USE_TOOLS+=		pkg-config xauth:run

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
BUILD_DEPENDS+=		ucpp-[0-9]*:../../devel/ucpp
CONFIGURE_ENV+=		ac_cv_path_RAWCPP="${PREFIX}/bin/ucpp -t -c90 -Uunix"
.elif empty(PKGSRC_COMPILER:Mgcc)
CONFIGURE_ENV+=		ac_cv_path_RAWCPP="cc -E -Uunix -"
.endif

.include "../../x11/libX11/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
