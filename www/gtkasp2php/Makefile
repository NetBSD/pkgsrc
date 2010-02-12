# $NetBSD: Makefile,v 1.17 2010/02/12 19:37:50 joerg Exp $
#

DISTNAME=	asp2php-0.76.17
PKGNAME=	gtk${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://65.108.58.129/asp2php/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://asp2php.naken.cc/
COMMENT=	Gtk+ version of utility to convert asp pages to php pages

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

BUILD_TARGET=	all gui
INSTALLATION_DIRS+=	bin

.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
