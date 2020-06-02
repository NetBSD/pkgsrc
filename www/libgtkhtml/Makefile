# $NetBSD: Makefile,v 1.84 2020/06/02 08:23:00 adam Exp $
#

DISTNAME=	libgtkhtml-2.6.3
PKGREVISION=	44
CATEGORIES=	www devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgtkhtml/2.6/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/
COMMENT=	Lightweight HTML rendering GTK2 widget

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake msgfmt pkg-config
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE=	libgtkhtml-2.0.pc.in

.include "../../textproc/libxml2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.14.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
