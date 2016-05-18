# $NetBSD: Makefile,v 1.1 2016/05/18 22:18:43 snj Exp $

DISTNAME=	redshift-1.11
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=jonls/}
GITHUB_RELEASE=	v1.11
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	http://jonls.dk/redshift/
COMMENT=	Adjust screen color temperature based on the position of the sun

LICENSE=	gnu-gpl-v3

BUILD_DEPENDS+=	gettext-tools-[0-9]*:../../devel/gettext-tools
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-gui
USE_LIBTOOL=	yes
USE_TOOLS+=	intltool pkg-config

.include "options.mk"

.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
