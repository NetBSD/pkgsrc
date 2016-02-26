# $NetBSD: Makefile,v 1.30 2016/02/26 11:27:15 jperkin Exp $

DISTNAME=		libXi-1.7.6
CATEGORIES=		x11 devel
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X Input extension library
LICENSE=		mit

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

CONFIGURE_ENV+=		LIB_MAN_SUFFIX=3 ac_cv_path_ASCIIDOC= ac_cv_path_XMLTO=
PKGCONFIG_OVERRIDE+=	xi.pc.in

SUBST_CLASSES+=		sosubdir
SUBST_STAGE.sosubdir=	pre-configure
SUBST_FILES.sosubdir=	man/*.man
SUBST_SED.sosubdir=	-e 's|\.so X|.so manlibmansuffix/X|'

CONFIGURE_ARGS.NetBSD+=	--disable-malloc0returnsnull

BUILDLINK_API_DEPENDS.inputproto+=	inputproto>=2.3
BUILDLINK_API_DEPENDS.libX11+=		libX11>=1.6
BUILDLINK_API_DEPENDS.libXext+=		libXext>=1.1
BUILDLINK_API_DEPENDS.xextproto+=	xextproto>=7.0.3
BUILDLINK_API_DEPENDS.xproto+=		xproto>=7.0.13
.include "../../x11/inputproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
