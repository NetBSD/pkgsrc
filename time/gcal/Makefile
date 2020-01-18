# $NetBSD: Makefile,v 1.28 2020/01/18 23:35:36 rillig Exp $
#

DISTNAME=		gcal-3.6.3
CATEGORIES=		time
MASTER_SITES=		${MASTER_SITE_GNU:=gcal/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.gnu.org/software/gcal/
COMMENT=		GNU version of the standard calendar utility
LICENSE=		gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
INFO_FILES=		yes

USE_TOOLS+=		msgfmt xgettext msgmerge awk

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
