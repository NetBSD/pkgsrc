# $NetBSD: Makefile,v 1.3 2006/02/05 23:11:26 joerg Exp $

DISTNAME= 		netscape7-acroread-1.0
PKGREVISION=		1

MAINTAINER=		jschauma@NetBSD.org
COMMENT=		Acrobat Reader 4 plugin for netscape7

DEPENDS+=		acroread-4.[0-9]*:../../print/acroread
CONFLICTS+=		netscape7-acroread3-[0-9]*
CONFLICTS+=		netscape7-acroread5-[0-9]*
CONFLICTS+=		netscape7-acroread7-[0-9]*

ACROREAD=		Acrobat4
ACRO_SUBDIR=		Browsers

.include "../../www/netscape7-acroread/Makefile.common"
