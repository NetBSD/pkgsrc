# $NetBSD: Makefile,v 1.20 2011/02/02 13:48:06 ryoon Exp $
#

DISTNAME=		gcal-3.6
CATEGORIES=		time
MASTER_SITES=		${MASTER_SITE_GNU:=gcal/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/gcal/
COMMENT=		GNU version of the standard calendar utility
LICENSE=		gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
INFO_FILES=		yes

USE_TOOLS+=		msgfmt xgettext msgmerge awk

CHECK_FILES_SKIP+=	lib/charset.alias

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
