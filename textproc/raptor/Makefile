# $NetBSD: Makefile,v 1.14 2006/02/05 23:11:07 joerg Exp $
#

DISTNAME=	raptor-1.0.0
PKGREVISION=	6
CATEGORIES=	textproc
MASTER_SITES=	http://www.redland.opensource.ac.uk/dist/source/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.redland.opensource.ac.uk/raptor/
COMMENT=	RDF Parser Toolkit written in C

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

PKGCONFIG_OVERRIDE+=	raptor.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
