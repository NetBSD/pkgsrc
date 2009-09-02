# $NetBSD: Makefile,v 1.5 2009/09/02 08:34:15 wiz Exp $

DISTNAME=		MozillaFirebird-bin-acroread-1.0
PKGREVISION=		2

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Acrobat Reader 4 plugin for firefox-bin

DEPENDS+=		acroread-4.[0-9]*:../../print/acroread
CONFLICTS+=		firefox-bin-acroread3-[0-9]*
CONFLICTS+=		firefox-bin-acroread5-[0-9]*

ACROREAD=		Acrobat4
ACRO_SUBDIR=		Browsers

.include "../../www/firefox-bin-acroread/Makefile.common"
.include "../../mk/bsd.pkg.mk"
