# $NetBSD: Makefile,v 1.5 2006/06/30 13:57:16 salo Exp $

DISTNAME= 		opera-acroread5-1.0
PKGREVISION=		3

MAINTAINER=		jschauma@NetBSD.org
COMMENT=		Acrobat Reader 5 plugin for opera

DEPENDS+=		acroread5-5.[0-9]*:../../print/acroread5
CONFLICTS+=		opera-acroread-[0-9]*
CONFLICTS+=		opera-acroread3-[0-9]*
CONFLICTS+=		opera-acroread7-[0-9]*

ACROREAD=		Acrobat5
ACRO_SUBDIR=		Browsers

.include "../../www/opera-acroread/Makefile.common"
