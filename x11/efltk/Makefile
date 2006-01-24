# $NetBSD: Makefile,v 1.5 2006/01/24 07:32:51 wiz Exp $
#

DISTNAME=	efltk-2.0.5
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ede/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://ede.sourceforge.net/
COMMENT=	Extended Fast Light Toolkit

WRKSRC=			${WRKDIR}/efltk
GNU_CONFIGURE=		yes
USE_LANGUAGES+=		c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake
BUILD_USES_MSGFMT=	yes

CONFIGURE_ARGS+=	--enable-iconv
CONFIGURE_ARGS+=	--enable-xft
CONFIGURE_ARGS+=	--enable-plugins
CONFIGURE_ARGS+=	--disable-unixODBC

.include "options.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
