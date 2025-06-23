# $NetBSD: Makefile,v 1.21 2025/06/23 01:25:14 zafer Exp $
#

DISTNAME=	asp2php-0.76.17
PKGNAME=	gtk${DISTNAME}
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	#http://65.108.58.129/asp2php/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://asp2php.naken.cc/
COMMENT=	Gtk+ version of utility to convert asp pages to php pages

MAKE_JOBS_SAFE=		no

BUILD_TARGET=		all gui
INSTALLATION_DIRS+=	bin

.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
