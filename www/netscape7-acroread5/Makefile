# $NetBSD: Makefile,v 1.2 2005/04/18 16:20:25 jschauma Exp $

DISTNAME= 		netscape7-acroread5-1.0

MAINTAINER=		jschauma@NetBSD.org
COMMENT=		Acrobat Reader 5 plugin for netscape7

DEPENDS+=		acroread5-5.[0-9]*:../../print/acroread5
CONFLICTS+=		netscape7-acroread-[0-9]*
CONFLICTS+=		netscape7-acroread3-[0-9]*
CONFLICTS+=		netscape7-acroread7-[0-9]*

ACROREAD=		Acrobat5
ACRO_SUBDIR=		Browsers

.include "../../www/netscape7-acroread/Makefile.common"
