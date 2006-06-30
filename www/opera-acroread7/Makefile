# $NetBSD: Makefile,v 1.7 2006/06/30 13:57:16 salo Exp $

DISTNAME= 		opera-acroread7-1.0
PKGREVISION=		2

MAINTAINER=		jschauma@NetBSD.org
COMMENT=		Acrobat Reader 7 plugin for opera

BROKEN_IN=		pkgsrc-2005Q4 pkgsrc-2006Q1

DEPENDS+=		acroread7-7.[0-9]*:../../print/acroread7
CONFLICTS+=		opera-acroread-[0-9]*
CONFLICTS+=		opera-acroread3-[0-9]*
CONFLICTS+=		opera-acroread5-[0-9]*

ACROREAD=		Acrobat7
ACRO_SUBDIR=		Browser

.include "../../www/opera-acroread/Makefile.common"
