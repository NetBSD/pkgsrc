# $NetBSD: Makefile,v 1.2 2006/02/05 23:11:26 joerg Exp $

DISTNAME= 		netscape7-acroread7-1.0
PKGREVISION=		1

MAINTAINER=		jschauma@NetBSD.org
COMMENT=		Acrobat Reader 7 plugin for netscape7

DEPENDS+=		acroread7-7.[0-9]*:../../print/acroread7
CONFLICTS+=		netscape7-acroread-[0-9]*
CONFLICTS+=		netscape7-acroread3-[0-9]*
CONFLICTS+=		netscape7-acroread5-[0-9]*

ACROREAD=		Acrobat7
ACRO_SUBDIR=		Browser

.include "../../www/netscape7-acroread/Makefile.common"
