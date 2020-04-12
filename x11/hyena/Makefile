# $NetBSD: Makefile,v 1.17 2020/04/12 08:29:19 adam Exp $

DISTNAME=	hyena-0.5
PKGREVISION=	15
CATEGORIES=	x11 devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/hyena/0.5/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	https://live.gnome.org/Hyena
COMMENT=	Hyena is a C\# library used to make awesome applications
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	# none

PKGCONFIG_OVERRIDE+=	build/pkg-config/hyena.data.sqlite.pc.in
PKGCONFIG_OVERRIDE+=	build/pkg-config/hyena.gui.pc.in
PKGCONFIG_OVERRIDE+=	build/pkg-config/hyena.pc.in

SUBST_CLASSES+=		fix-mcs
SUBST_STAGE.fix-mcs=	pre-configure
SUBST_MESSAGE.fix-mcs=	Fix compiler name
SUBST_FILES.fix-mcs=	configure
SUBST_SED.fix-mcs=	-e 's,gmcs,mcs,'

.include "../../x11/gtk-sharp/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
