# $NetBSD: Makefile,v 1.2 2005/08/26 22:44:01 xtraeme Exp $

DISTNAME= 		MozillaFirebird-bin-acroread7-1.0

MAINTAINER=		kei@NetBSD.org
COMMENT=		Acrobat Reader 5 plugin for firefox-bin

DEPENDS+=		acroread7>=7.0:../../print/acroread7
CONFLICTS+=		firefox-bin-acroread5-[0-9]*
CONFLICTS+=		firefox-bin-acroread3-[0-9]*
CONFLICTS+=		firefox-bin-acroread-[0-9]*

ACROREAD=		Acrobat7
BROWSER=		Browser

.include "../../www/firefox-bin-acroread/Makefile.common"
