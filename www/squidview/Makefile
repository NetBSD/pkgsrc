# $NetBSD: Makefile,v 1.1 2013/12/09 10:32:18 sborrill Exp $
#

DISTNAME=	squidview-0.80
CATEGORIES=	www
MASTER_SITES=	http://www.rillion.net/squidview/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rillion.net/squidview/
COMMENT=	Program which monitors and displays squid logs
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

.include "../../www/squid/Makefile.common"

SUBST_CLASSES+=	files
SUBST_STAGE.files=	post-patch
SUBST_FILES.files=	squidview.h squidview.1
SUBST_SED.files=	-e "s|/var/log/squid|${LOGDIR}|g"
SUBST_MESSAGE.files=	Fixing logfile location.

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
