# $NetBSD: Makefile,v 1.6 2002/07/15 14:46:15 fredb Exp $
#

DISTNAME=		glibwww-0.2
PKGREVISION=		2
CATEGORIES=		www gnome devel
MASTER_SITES=		${MASTER_SITE_GNOME:=unstable/sources/glibwww/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		event register functions that use the glib event loop

BUILDLINK_DEPENDS.gnome-libs=	gnome-libs>=1.4.1.2nb1

USE_BUILDLINK_ONLY=	YES

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

post-patch:
	cd ${WRKSRC};							\
	for file in src/Makefile.in; do					\
		${SED}	-e "s|[	 ]*-I\$$(includedir)||g"		\
			$${file} > $${file}.fixed;			\
		${MV} -f $${file}.fixed $${file};			\
	done

.include "../../www/libwww/buildlink.mk"
.include "../../x11/gnome-libs/buildlink.mk"

.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
