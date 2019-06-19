# $NetBSD: Makefile,v 1.35 2019/06/19 17:30:51 wiz Exp $

DISTNAME=		libXi-1.7.10
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

BUILDLINK_API_DEPENDS.libX11+=		libX11>=1.6
BUILDLINK_API_DEPENDS.libXext+=		libXext>=1.1
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
