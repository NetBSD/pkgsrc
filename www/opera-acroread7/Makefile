# $NetBSD: Makefile,v 1.5 2006/02/05 23:11:26 joerg Exp $

DISTNAME= 		opera-acroread7-1.0
PKGREVISION=		1

MAINTAINER=		jschauma@NetBSD.org
COMMENT=		Acrobat Reader 7 plugin for opera

BROKEN_IN=		pkgsrc-2005Q4

DEPENDS+=		acroread7-7.[0-9]*:../../print/acroread7
CONFLICTS+=		opera-acroread-[0-9]*
CONFLICTS+=		opera-acroread3-[0-9]*
CONFLICTS+=		opera-acroread5-[0-9]*

ACROREAD=		Acrobat7
ACRO_SUBDIR=		Browser

.include "../../www/opera-acroread/Makefile.common"
