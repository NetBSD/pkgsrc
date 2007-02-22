# $NetBSD: Makefile,v 1.3 2007/02/22 19:27:19 wiz Exp $

DISTNAME=	MozillaFirebird-bin-acroread-1.0
PKGREVISION=		1

MAINTAINER=		kei@NetBSD.org
COMMENT=		Acrobat Reader 4 plugin for firefox-bin

DEPENDS+=		acroread-4.[0-9]*:../../print/acroread
CONFLICTS+=		firefox-bin-acroread3-[0-9]*
CONFLICTS+=		firefox-bin-acroread5-[0-9]*

ACROREAD=		Acrobat4

.include "../../www/firefox-bin-acroread/Makefile.common"
