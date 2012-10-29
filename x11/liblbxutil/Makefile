# $NetBSD: Makefile,v 1.5 2012/10/29 05:06:37 asau Exp $
#

DISTNAME=		liblbxutil-1.0.1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Low-Bandwidth X (LBX) utilities library

USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/lbxutil.pc.in
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

BROKEN=			Unsupported by modern X.org

.include "../../mk/bsd.prefs.mk"

.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
MAKE_ENV+=	CC_FOR_BUILD=${NATIVE_CC:Q} CPPFLAGS_FOR_BUILD=-I${PREFIX}/include
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
