# $NetBSD: Makefile,v 1.8 2009/01/23 21:14:16 jschauma Exp $

DISTNAME=		opera-acroread5-1.0
PKGREVISION=		4

MAINTAINER=		pkgsrc-users@@NetBSD.org
COMMENT=		Acrobat Reader 5 plugin for opera

DEPENDS+=		acroread5-5.[0-9]*:../../print/acroread5
CONFLICTS+=		opera-acroread-[0-9]*
CONFLICTS+=		opera-acroread3-[0-9]*
CONFLICTS+=		opera-acroread7-[0-9]*

ACROREAD=		Acrobat5
ACRO_SUBDIR=		Browsers

.include "../../www/opera-acroread/Makefile.common"
.include "../../mk/bsd.pkg.mk"
