# $NetBSD: Makefile,v 1.1.1.1 2005/03/05 09:42:05 jmmv Exp $
#

DISTNAME=	clearlooks-0.4
PKGNAME=	gtk2-engines-${DISTNAME}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=clearlooks/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/clearlooks
COMMENT=	New and modern-looking GTK2+ engine, based on Bluecurve

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_DIRS+=		xdg-1.1
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes

CONFIGURE_ENV+=		gnome_prefix="${PREFIX}"

SHLIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
