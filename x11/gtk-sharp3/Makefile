# $NetBSD: Makefile,v 1.26 2024/05/29 16:34:59 adam Exp $

DISTNAME=	gtk-sharp-2.99.3
PKGREVISION=	24
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtk-sharp/2.99/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.mono-project.com/docs/gui/gtksharp/
COMMENT=	.NET bindings for GTK+3
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes

USE_TOOLS+=	pkg-config gmake perl:run
USE_LIBTOOL=	yes

REPLACE_PERL+=	parser/gapi_pp.pl
REPLACE_PERL+=	parser/gapi2xml.pl

SUBST_CLASSES+=		mcs
SUBST_STAGE.mcs=	pre-configure
SUBST_FILES.mcs+=	configure
SUBST_SED.mcs=		-e 's|gmcs|mcs|'

.include "../../lang/mono/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
