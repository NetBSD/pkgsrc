# $NetBSD: Makefile,v 1.18 2008/04/30 13:38:16 jmmv Exp $
#

DISTNAME=	fast-user-switch-applet-2.22.0
CATEGORIES=	misc gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/fast-user-switch-applet/2.22/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ignore-your.tv/fusa/
COMMENT=	Switch between users from the GNOME Panel

DEPENDS+=		gdm>=2.16.0:../../x11/gdm

GNU_CONFIGURE=		yes
USE_DIRS+=		gnome2-1.6
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_X11=		yes

.include "../../mk/bsd.prefs.mk"

EVAL_PREFIX=		PREFIX.gdm
PREFIX.gdm_DEFAULT=	${LOCALBASE}
CONFIGURE_ARGS+=	--with-gdm-setup=${PREFIX.gdm}/sbin/gdmsetup

.if defined(PKG_SYSCONFDIR.gdm)
CONFIGURE_ARGS+=	--with-gdm-config=${PKG_SYSCONFDIR.gdm}/custom.conf
.else
CONFIGURE_ARGS+=	--with-gdm-config=${PKG_SYSCONFBASE}/gdm/custom.conf
.endif

GCONF_SCHEMAS=		fast-user-switch-applet.schemas

BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.8.0

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../devel/GConf/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
