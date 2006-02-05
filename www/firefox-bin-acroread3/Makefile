# $NetBSD: Makefile,v 1.2 2006/02/05 23:11:21 joerg Exp $

DISTNAME= 		MozillaFirebird-bin-acroread3-1.0
PKGREVISION=		1

MAINTAINER=		kei@NetBSD.org
COMMENT=		Acrobat Reader 3 plugin for firefox-bin

DEPENDS+=		acroread3-3.[0-9]*:../../print/acroread
CONFLICTS+=		firefox-bin-acroread-[0-9]*
CONFLICTS+=		firefox-bin-acroread5-[0-9]*

ACROREAD=		Acrobat3

.include "../../www/firefox-bin-acroread/Makefile.common"
