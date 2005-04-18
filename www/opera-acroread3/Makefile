# $NetBSD: Makefile,v 1.3 2005/04/18 16:20:25 jschauma Exp $

DISTNAME= 		opera-acroread3-1.0
PKGREVISION=		1

MAINTAINER=		jschauma@NetBSD.org
COMMENT=		Acrobat Reader 3 plugin for opera

DEPENDS+=		acroread3-3.[0-9]*:../../print/acroread3
CONFLICTS+=		opera-acroread-[0-9]*
CONFLICTS+=		opera-acroread5-[0-9]*
CONFLICTS+=		opera-acroread7-[0-9]*

ACROREAD=		Acrobat3
ACRO_SUBDIR=		Browsers

.include "../../www/opera-acroread/Makefile.common"
