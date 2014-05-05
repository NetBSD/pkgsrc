# $NetBSD: Makefile,v 1.54 2014/05/05 00:48:28 ryoon Exp $
#

DISTNAME=	gnome-sharp-2.24.2
PKGREVISION=	32
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-sharp/2.24/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mono-project.com/GtkSharp
COMMENT=	C\# bindings for the GNOME platform
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
MAKE_JOBS_SAFE=		no

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == NetBSD
.  if !empty(OS_VERSION:M5.99.*) || !empty(OS_VERSION:M[6789].*)
CONFIGURE_ENV+=		EXTRACSDEFINES=-define:TIMET_IS_64BITS
.  else
CONFIGURE_ENV+=		EXTRACSDEFINES=-define:TIMET_IS_32BITS
.  endif
.endif

PKGCONFIG_OVERRIDE+=	art/art-sharp-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gconf/GConf/gconf-sharp-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gconf/GConf.PropertyEditors/gconf-sharp-peditors-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gnome/gnome-sharp-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gnomevfs/gnome-vfs-sharp-2.0.pc.in

SUBST_CLASSES=		pc
SUBST_STAGE.pc=		post-patch
SUBST_FILES.pc=		${PKGCONFIG_OVERRIDE}
SUBST_SED.pc=		-e "s|\$${pcfiledir}/../..|@prefix@|g"
SUBST_MESSAGE.pc=	Fixing hardcoded paths.

BUILDLINK_API_DEPENDS.libgnomeui+=	libgnomeui>=2.23.0
.include "../../devel/libgnomeui/buildlink3.mk"
BUILDLINK_API_DEPENDS.libart+=		libart>=2.3.20
.include "../../graphics/libart/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgnomecanvas+=	libgnomecanvas>=2.20.0
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../lang/mono2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gnome-vfs+=	gnome-vfs>=2.22.0
.include "../../sysutils/gnome-vfs/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=		gtk2+>=2.13.0
.include "../../x11/gtk2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk-sharp+=	gtk-sharp>=2.12.2
.include "../../x11/gtk-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
