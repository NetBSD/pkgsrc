# $NetBSD: Makefile,v 1.2 2006/02/05 23:11:21 joerg Exp $

DISTNAME= 		MozillaFirebird-bin-acroread5-1.0
PKGREVISION=		1

MAINTAINER=		kei@NetBSD.org
COMMENT=		Acrobat Reader 5 plugin for firefox-bin

DEPENDS+=		acroread5-5.[0-9]*:../../print/acroread5
CONFLICTS+=		firefox-bin-acroread3-[0-9]*
CONFLICTS+=		firefox-bin-acroread-[0-9]*

ACROREAD=		Acrobat5

.include "../../www/firefox-bin-acroread/Makefile.common"
