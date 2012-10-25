# $NetBSD: Makefile,v 1.2 2012/10/25 06:57:07 asau Exp $
#

DISTNAME=	xml-coreutils-0.8a
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xml-coreutils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xml-coreutils.sourceforge.net/
COMMENT=	Command line tools for XML processing
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes

.include "../../textproc/expat/buildlink3.mk"
.include "../../devel/libslang/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
