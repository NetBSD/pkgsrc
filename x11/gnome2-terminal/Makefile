# $NetBSD: Makefile,v 1.7 2003/05/02 11:57:04 wiz Exp $
#

DISTNAME=		gnome-terminal-2.0.1
PKGNAME=		${DISTNAME:S/-/2-/}
PKGREVISION=	4
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-terminal/2.0/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		sab@posix.org.uk
HOMEPAGE=		http://www.gnome.org/
COMMENT=		xterm like terminal program for GNOME 2

BUILD_USES_MSGFMT=	YES
DEPENDS=		gnome2-dirs>=1.0:../../misc/gnome2-dirs

USE_PERL5=		build
GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_GMAKE=		YES
USE_X11=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GCONF2_SCHEMAS= 	gnome-terminal.schemas

.include "../../x11/gtk2/buildlink2.mk"
.include "../../x11/libzvt/buildlink2.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/libglade2/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../mk/bsd.pkg.mk"
