# $NetBSD: Makefile,v 1.10 2020/01/18 23:35:32 rillig Exp $
#

DISTNAME=	scew-0.3.1
PKGREVISION=	3
CATEGORIES=	textproc devel
MASTER_SITES=	http://download.savannah.nongnu.org/releases/scew/

MAINTAINER=	thorbjorn@jemander.net
HOMEPAGE=	https://www.nongnu.org/scew/
COMMENT=	Light-weight DOM-like object model API for Expat

GNU_CONFIGURE=	YES

PKGCONFIG_OVERRIDE=	etc/pkg-config/scew.pc.in

.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
