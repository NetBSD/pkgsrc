# $NetBSD: Makefile,v 1.4 2006/02/05 23:11:26 joerg Exp $

DISTNAME= 		opera-acroread3-1.0
PKGREVISION=		2

MAINTAINER=		jschauma@NetBSD.org
COMMENT=		Acrobat Reader 3 plugin for opera

DEPENDS+=		acroread3-3.[0-9]*:../../print/acroread3
CONFLICTS+=		opera-acroread-[0-9]*
CONFLICTS+=		opera-acroread5-[0-9]*
CONFLICTS+=		opera-acroread7-[0-9]*

ACROREAD=		Acrobat3
ACRO_SUBDIR=		Browsers

.include "../../www/opera-acroread/Makefile.common"
