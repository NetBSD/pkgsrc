# $NetBSD: Makefile,v 1.4 2007/07/30 16:12:56 jlam Exp $

DISTNAME=		MozillaFirebird-bin-acroread-1.0
PKGREVISION=		2

MAINTAINER=		kei@NetBSD.org
COMMENT=		Acrobat Reader 4 plugin for firefox-bin

DEPENDS+=		acroread-4.[0-9]*:../../print/acroread
CONFLICTS+=		firefox-bin-acroread3-[0-9]*
CONFLICTS+=		firefox-bin-acroread5-[0-9]*

ACROREAD=		Acrobat4
ACRO_SUBDIR=		Browsers

.include "../../www/firefox-bin-acroread/Makefile.common"
.include "../../mk/bsd.pkg.mk"
