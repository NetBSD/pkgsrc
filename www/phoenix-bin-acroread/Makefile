# $NetBSD: Makefile,v 1.2 2003/05/07 16:29:38 kei Exp $

DISTNAME= 		phoenix-bin-acroread-1.0
PKGREVISION=		1

MAINTAINER=		kei@netbsd.org
COMMENT=		Acrobat Reader 4 plugin for phoenix-bin

DEPENDS+=		acroread-4.[0-9]*:../../print/acroread
CONFLICTS+=		phoenix-bin-acroread3-[0-9]*
CONFLICTS+=		phoenix-bin-acroread5-[0-9]*

ACROREAD=		Acrobat4

.include "../../www/phoenix-bin-acroread/Makefile.common"
