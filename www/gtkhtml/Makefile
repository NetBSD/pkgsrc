# $NetBSD: Makefile,v 1.20 2002/09/10 16:06:51 wiz Exp $

DISTNAME=		gtkhtml-1.0.1
PKGREVISION=		2
CATEGORIES=		www gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=unstable/sources/gtkhtml/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Lightweight HTML rendering/printing/editing engine

USE_BUILDLINK_ONLY=	YES
USE_X11BASE=		YES
USE_LIBTOOL=		YES
USE_GMAKE=		YES
GNU_CONFIGURE=		YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

post-patch:
	cd ${WRKSRC};							\
	for file in							\
		src/Makefile.in						\
		capplet/Makefile.in					\
		components/http-storage-module/Makefile.in;		\
	do								\
		${SED}	-e "s|[	 ]*-I\$$(includedir)||g"		\
			$${file} > $${file}.fixed;			\
		${MV} -f $${file}.fixed $${file};			\
	done

.include "../../devel/bonobo/buildlink.mk"
.include "../../devel/gal/buildlink.mk"
.include "../../print/gnome-print/buildlink.mk"
.include "../../www/glibwww/buildlink.mk"
.include "../../www/libghttp/buildlink.mk"
.include "../../x11/controlcenter/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
