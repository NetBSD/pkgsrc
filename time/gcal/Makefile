# $NetBSD: Makefile,v 1.17 2009/07/07 20:22:42 joerg Exp $
#

DISTNAME=		gcal-3.01
PKGREVISION=		5
CATEGORIES=		time
MASTER_SITES=		${MASTER_SITE_GNU:=gcal/}

MAINTAINER=		atatat@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/gcal/gcal.html
COMMENT=		GNU version of the standard calendar utility

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes

INFO_FILES=		# PLIST
GNU_CONFIGURE=		yes
USE_TOOLS+=		msgfmt
BROKEN_GETTEXT_DETECTION=	yes

REPLACE_PERL+=		misc/gcalltx/gcalltxp.in
USE_TOOLS+=		perl:run

INSTALL_MAKE_FLAGS+=	gnulocaledir=${DESTDIR}${PREFIX}/${PKGLOCALEDIR}/locale \
			bindir=${DESTDIR}${PREFIX}/bin \
			packagedatadir=${DESTDIR}${PREFIX}/share/gcal \
			infodir=${DESTDIR}${PREFIX}/${PKGINFODIR} \
			mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
