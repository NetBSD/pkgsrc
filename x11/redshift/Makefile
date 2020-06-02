# $NetBSD: Makefile,v 1.5 2020/06/02 08:25:03 adam Exp $

DISTNAME=	redshift-1.12
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=jonls/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	http://jonls.dk/redshift/
COMMENT=	Adjust screen color temperature based on the position of the sun
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	intltool pkg-config
USE_TOOLS+=	msgfmt msgmerge xgettext

CONFIGURE_ARGS+=	--disable-gui

.include "options.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
