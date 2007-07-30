# $NetBSD: Makefile,v 1.4 2007/07/30 16:12:57 jlam Exp $

DISTNAME=		MozillaFirebird-bin-acroread5-1.0
PKGREVISION=		2

MAINTAINER=		kei@NetBSD.org
COMMENT=		Acrobat Reader 5 plugin for firefox-bin

DEPENDS+=		acroread5-5.[0-9]*:../../print/acroread5
CONFLICTS+=		firefox-bin-acroread3-[0-9]*
CONFLICTS+=		firefox-bin-acroread-[0-9]*

ACROREAD=		Acrobat5
ACRO_SUBDIR=		Browsers

.include "../../www/firefox-bin-acroread/Makefile.common"
.include "../../mk/bsd.pkg.mk"
