# $NetBSD: Makefile,v 1.8 2003/05/02 11:56:36 wiz Exp $
#

DISTNAME=	metacity-2.4.34
PKGREVISION=	1
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/metacity/2.4/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnome.org/softwaremap/projects/Metacity
COMMENT=	gnome-compliant window manager

BUILD_USES_MSGFMT=	yes
DEPENDS=		gnome2-dirs>=1.0:../../misc/gnome2-dirs

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-included-gettext
USE_GMAKE=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
USE_X11=		yes
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes

GCONF2_SCHEMAS=		metacity.schemas

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/libglade2/buildlink2.mk"
.include "../../net/ORBit2/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
