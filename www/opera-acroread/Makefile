# $NetBSD: Makefile,v 1.5 2006/06/11 20:49:06 jschauma Exp $

DISTNAME= 		opera-acroread-1.0
PKGREVISION=		2

MAINTAINER=		jschauma@NetBSD.org
COMMENT=		Acrobat Reader 4 plugin for opera

DEPENDS+=		acroread-4.[0-9]*:../../print/acroread
CONFLICTS+=		opera-acroread3-[0-9]*
CONFLICTS+=		opera-acroread5-[0-9]*
CONFLICTS+=		opera-acroread7-[0-9]*

ACROREAD=		Acrobat4
ACRO_SUBDIR=		Browsers

.include "../../www/opera-acroread/Makefile.common"
