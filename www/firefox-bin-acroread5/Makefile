# $NetBSD: Makefile,v 1.5 2009/09/02 08:34:15 wiz Exp $

DISTNAME=		MozillaFirebird-bin-acroread5-1.0
PKGREVISION=		2

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Acrobat Reader 5 plugin for firefox-bin

DEPENDS+=		acroread5-5.[0-9]*:../../print/acroread5
CONFLICTS+=		firefox-bin-acroread3-[0-9]*
CONFLICTS+=		firefox-bin-acroread-[0-9]*

ACROREAD=		Acrobat5
ACRO_SUBDIR=		Browsers

.include "../../www/firefox-bin-acroread/Makefile.common"
.include "../../mk/bsd.pkg.mk"
