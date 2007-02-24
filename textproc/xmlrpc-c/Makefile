# $NetBSD: Makefile,v 1.1.1.1 2007/02/24 11:00:51 wiz Exp $
#

DISTNAME=	xmlrpc-c-1.09.00
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xmlrpc-c/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xmlrpc-c.sourceforge.net/
COMMENT=	Library for writing an XML-RPC server or client in C or C++

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
MAKE_FILE=	GNUmakefile

.include "../../textproc/expat/buildlink3.mk"
.include "../../www/libwww/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
