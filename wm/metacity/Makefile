# $NetBSD: Makefile,v 1.2 2002/09/10 16:06:50 wiz Exp $
#

DISTNAME=	metacity-2.3.377
PKGREVISION=	1
CATEGORIES=	wm
MASTER_SITES=	http://people.redhat.com/~hp/metacity/

MAINTAINER=	packages@netbsd.org
#HOMEPAGE=	
COMMENT=	gnome-compliant window manager

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-included-gettext
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

CONFIGURE_ENV+=		PKG_CONFIG=${BUILDLINK_DIR}/bin/pkg-config

BUILD_USES_MSGFMT=	yes

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/GConf2/buildlink.mk"
.include "../../x11/gtk2/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
