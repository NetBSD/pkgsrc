# $NetBSD: Makefile,v 1.1.1.1 2003/08/30 16:18:58 xtraeme Exp $
#

DISTNAME=	raptor-0.9.12
CATEGORIES=	textproc
MASTER_SITES=	http://www.redland.opensource.ac.uk/dist/source/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.redland.opensource.ac.uk/raptor/
COMMENT=	RDF Parser Toolkit written in C

USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=    ${WRKSRC}/raptor.pc.in

.include "../../textproc/libxml2/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../www/curl/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
