# $NetBSD: Makefile,v 1.9 2009/01/23 21:14:16 jschauma Exp $

DISTNAME=		opera-acroread-1.0
PKGREVISION=		4

MAINTAINER=		pkgsrc-users@@NetBSD.org
COMMENT=		Acrobat Reader 4 plugin for opera

DEPENDS+=		acroread-4.[0-9]*:../../print/acroread
CONFLICTS+=		opera-acroread3-[0-9]*
CONFLICTS+=		opera-acroread5-[0-9]*
CONFLICTS+=		opera-acroread7-[0-9]*

ACROREAD=		Acrobat4
ACRO_SUBDIR=		Browsers

.include "../../www/opera-acroread/Makefile.common"
.include "../../mk/bsd.pkg.mk"
