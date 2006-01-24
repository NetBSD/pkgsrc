# $NetBSD: Makefile,v 1.4 2006/01/24 07:32:39 wiz Exp $
#

DISTNAME=	scew-0.3.1
PKGREVISION=	2
CATEGORIES=	textproc devel
MASTER_SITES=	http://www.ccd.uab.es/~aleix/scew/

MAINTAINER=	thorbjorn@jemander.net
HOMEPAGE=	http://www.nongnu.org/scew/
COMMENT=	Light-weight DOM-like object model API for Expat

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	YES

PKGCONFIG_OVERRIDE=	etc/pkg-config/scew.pc.in

.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
