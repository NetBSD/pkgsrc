# $NetBSD: Makefile,v 1.3 2002/09/10 16:53:02 wiz Exp $
#

DISTNAME=	metacity-2.3.377
PKGREVISION=	1
CATEGORIES=	wm
MASTER_SITES=	http://people.redhat.com/~hp/metacity/

MAINTAINER=	packages@netbsd.org
#HOMEPAGE=	
COMMENT=	gnome-compliant window manager

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-included-gettext
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
USE_X11=		yes
USE_BUILDLINK2=		yes

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/GConf2/buildlink2.mk"
.include "../../net/ORBit2/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../devel/ptl2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
