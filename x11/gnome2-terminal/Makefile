# $NetBSD: Makefile,v 1.28 2004/04/01 18:50:21 jmmv Exp $
#

DISTNAME=		gnome-terminal-2.6.0
PKGNAME=		${DISTNAME:S/-/2-/}
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-terminal/2.6/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		sab@posix.org.uk
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Xterm like terminal program for GNOME 2

BUILD_USES_MSGFMT=	YES
DEPENDS=		gnome2-dirs>=1.5:../../misc/gnome2-dirs

CONFLICTS=		gnome-core-[0-9]*

USE_PERL5=		build
GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES
USE_GNU_TOOLS+=		make
USE_X11=		YES
USE_LIBTOOL=		YES

GCONF2_SCHEMAS= 	gnome-terminal.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libzvt/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../x11/vte/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
