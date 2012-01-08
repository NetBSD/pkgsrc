# $NetBSD: Makefile,v 1.23 2012/01/08 03:49:53 sbd Exp $
#

DISTNAME=		gcal-3.6.1
PKGREVISION=		1
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
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
