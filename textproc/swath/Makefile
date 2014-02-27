# $NetBSD: Makefile,v 1.3 2014/02/27 12:43:31 obache Exp $
#

DISTNAME=	swath-0.4.3
CATEGORIES=	textproc
MASTER_SITES=	ftp://linux.thai.net/pub/ThaiLinux/software/swath/ 	\
		http://linux.thai.net/pub/ThaiLinux/software/swath/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://linux.thai.net/projects/thailatex
COMMENT=	Smart Word Analysis for THai
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

.include "../../devel/libdatrie/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
