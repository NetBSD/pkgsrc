# $NetBSD: Makefile,v 1.27 2013/07/21 09:11:43 shattered Exp $
#

DISTNAME=		gcal-3.6.3
CATEGORIES=		time
MASTER_SITES=		${MASTER_SITE_GNU:=gcal/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/gcal/
COMMENT=		GNU version of the standard calendar utility
LICENSE=		gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
INFO_FILES=		yes

USE_TOOLS+=		msgfmt xgettext msgmerge awk

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
