# $NetBSD: Makefile,v 1.58 2026/05/15 17:01:06 wiz Exp $

DISTNAME=	uhttpmock-0.11.0
PKGREVISION=	8
CATEGORIES=	www devel
MASTER_SITES=	https://tecnocode.co.uk/downloads/uhttpmock/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/groups/uhttpmock
COMMENT=	Library for mocking web service APIs which use HTTP or HTTPS
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=	gtk-doc-[0-9]*:../../textproc/gtk-doc
TOOL_DEPENDS+=	glib2-introspection-[0-9]*:../../devel/glib2-introspection

USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libuhttpmock/libuhttpmock.pc.in

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--no-as-needed

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../net/libsoup3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
