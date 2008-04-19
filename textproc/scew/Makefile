# $NetBSD: Makefile,v 1.6 2008/04/19 05:45:55 obache Exp $
#

DISTNAME=	scew-0.3.1
PKGREVISION=	3
CATEGORIES=	textproc devel
MASTER_SITES=	http://download.savannah.nongnu.org/releases/scew/

MAINTAINER=	thorbjorn@jemander.net
HOMEPAGE=	http://www.nongnu.org/scew/
COMMENT=	Light-weight DOM-like object model API for Expat

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	YES

PKGCONFIG_OVERRIDE=	etc/pkg-config/scew.pc.in

.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
