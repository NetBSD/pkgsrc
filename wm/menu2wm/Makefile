# $NetBSD: Makefile,v 1.2 2003/12/04 19:48:26 xtraeme Exp $
#

DISTNAME=	menu2wm-0.1
PKGREVISION=	1
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=menu2wm/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://menu2wm.sourceforge.net/
COMMENT=	Convert an XML menu to the format used by common WMs

USE_BUILDLINK2=	YES

.include "../../devel/buildtool/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
