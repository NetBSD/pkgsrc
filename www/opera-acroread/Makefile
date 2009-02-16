# $NetBSD: Makefile,v 1.10 2009/02/16 13:55:00 joerg Exp $

DISTNAME=		opera-acroread-1.0
PKGREVISION=		4

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Acrobat Reader 4 plugin for opera

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		acroread-4.[0-9]*:../../print/acroread
CONFLICTS+=		opera-acroread3-[0-9]*
CONFLICTS+=		opera-acroread5-[0-9]*
CONFLICTS+=		opera-acroread7-[0-9]*

ACROREAD=		Acrobat4
ACRO_SUBDIR=		Browsers

.include "../../www/opera-acroread/Makefile.common"
.include "../../mk/bsd.pkg.mk"
