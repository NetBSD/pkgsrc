# $NetBSD: Makefile,v 1.4 2015/08/17 17:11:30 wiz Exp $
#

DISTNAME=	xml-coreutils-0.8a
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xml-coreutils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xml-coreutils.sourceforge.net/
COMMENT=	Command line tools for XML processing
LICENSE=	gnu-gpl-v3
USE_LANGUAGES=	c99
GNU_CONFIGURE=	yes

.include "../../textproc/expat/buildlink3.mk"
.include "../../devel/libslang/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
