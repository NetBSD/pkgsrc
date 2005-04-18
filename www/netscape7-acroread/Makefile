# $NetBSD: Makefile,v 1.2 2005/04/18 16:20:25 jschauma Exp $

DISTNAME= 		netscape7-acroread-1.0

MAINTAINER=		jschauma@NetBSD.org
COMMENT=		Acrobat Reader 4 plugin for netscape7

DEPENDS+=		acroread-4.[0-9]*:../../print/acroread
CONFLICTS+=		netscape7-acroread3-[0-9]*
CONFLICTS+=		netscape7-acroread5-[0-9]*
CONFLICTS+=		netscape7-acroread7-[0-9]*

ACROREAD=		Acrobat4
ACRO_SUBDIR=		Browsers

.include "../../www/netscape7-acroread/Makefile.common"
