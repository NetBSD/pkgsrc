# $NetBSD: Makefile,v 1.4 2003/12/04 19:48:26 xtraeme Exp $
#

DISTNAME=	raptor-1.0.0
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.redland.opensource.ac.uk/dist/source/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.redland.opensource.ac.uk/raptor/
COMMENT=	RDF Parser Toolkit written in C

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=	${WRKSRC}/raptor.pc.in

.include "../../devel/glib2/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../www/curl/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
