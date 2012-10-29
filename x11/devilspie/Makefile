# $NetBSD: Makefile,v 1.54 2012/10/29 05:06:09 asau Exp $

DISTNAME=		devilspie-0.22
PKGREVISION=		15
CATEGORIES=		x11
MASTER_SITES=		http://www.burtonini.com/computing/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.burtonini.com/blog/computers/devilspie/
COMMENT=		Window-matching utility to customize window behavior
LICENSE=		gnu-gpl-v2

BUILD_DEPENDS+=		libxslt>=1.0:../../textproc/libxslt

USE_TOOLS+=		intltool msgfmt pkg-config
GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
TEST_TARGET=		check
INSTALLATION_DIRS=	share/doc/devilspie
LDFLAGS.DragonFly=	-lX11

post-install:
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/devilspie/

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.9.1
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
