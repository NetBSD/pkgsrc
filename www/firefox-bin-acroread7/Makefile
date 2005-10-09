# $NetBSD: Makefile,v 1.3 2005/10/09 08:53:35 rillig Exp $

DISTNAME= 		MozillaFirebird-bin-acroread7-1.0

MAINTAINER=		kei@NetBSD.org
COMMENT=		Acrobat Reader 7 plugin for firefox-bin

DEPENDS+=		acroread7>=7.0:../../print/acroread7
CONFLICTS+=		firefox-bin-acroread5-[0-9]*
CONFLICTS+=		firefox-bin-acroread3-[0-9]*
CONFLICTS+=		firefox-bin-acroread-[0-9]*

ACROREAD=		Acrobat7
BROWSER=		Browser

.include "../../www/firefox-bin-acroread/Makefile.common"
