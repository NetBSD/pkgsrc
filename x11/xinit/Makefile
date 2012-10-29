# $NetBSD: Makefile,v 1.17 2012/10/29 05:07:12 asau Exp $
#

DISTNAME=		xinit-1.3.2
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X init program
LICENSE=		mit

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
