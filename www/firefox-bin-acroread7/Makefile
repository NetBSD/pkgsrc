# $NetBSD: Makefile,v 1.5 2007/02/22 19:27:20 wiz Exp $

DISTNAME=	MozillaFirebird-bin-acroread7-1.0
PKGREVISION=		1

MAINTAINER=		kei@NetBSD.org
COMMENT=		Acrobat Reader 7 plugin for firefox-bin

DEPENDS+=		acroread7>=7.0:../../print/acroread7
CONFLICTS+=		firefox-bin-acroread5-[0-9]*
CONFLICTS+=		firefox-bin-acroread3-[0-9]*
CONFLICTS+=		firefox-bin-acroread-[0-9]*

ACROREAD=		Acrobat7
BROWSER=		Browser

.include "../../www/firefox-bin-acroread/Makefile.common"
