# $NetBSD: Makefile,v 1.1.1.1 2003/06/01 11:38:15 jmmv Exp $
#

DISTNAME=	metacity-setup-0.7.1
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=metacity-setup/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.sourceforge.net/projects/metacity-setup/
COMMENT=	Configuration editor for Metacity

BUILD_USES_MSGFMT=	YES
DEPENDS=		gnome2-dirs>=1.2:../../misc/gnome2-dirs

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
USE_PERL5=		build
USE_PKGLOCALEDIR=	yes

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../devel/GConf2/buildlink2.mk"
.include "../../devel/libglade2/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../textproc/intltool/buildlink2.mk"
.include "../../sysutils/gnome-vfs2/buildlink2.mk"
.include "../../wm/metacity/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
