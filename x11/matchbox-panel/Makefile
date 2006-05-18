# $NetBSD: Makefile,v 1.9 2006/05/18 20:30:02 wiz Exp $
#

DISTNAME=		matchbox-panel-0.9.2
PKGREVISION=		3
CATEGORIES=		x11
MASTER_SITES=		http://projects.o-hand.com/matchbox/sources/matchbox-panel/0.9/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://projects.o-hand.com/matchbox/
COMMENT=		Panel for Matchbox

BROKEN_IN=		pkgsrc-2006Q1

BROKEN_GETTEXT_DETECTION=	yes

USE_DIRS+=		gnome2-1.5
USE_TOOLS+=		gmake msgfmt
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--enable-small-icons
CONFIGURE_ARGS+=	--enable-startup-notification
CONFIGURE_ARGS+=	--enable-nls

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../devel/libmatchbox/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
