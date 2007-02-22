# $NetBSD: Makefile,v 1.7 2007/02/22 19:27:20 wiz Exp $

DISTNAME=	opera-acroread-1.0
PKGREVISION=		3

MAINTAINER=		jschauma@NetBSD.org
COMMENT=		Acrobat Reader 4 plugin for opera

DEPENDS+=		acroread-4.[0-9]*:../../print/acroread
CONFLICTS+=		opera-acroread3-[0-9]*
CONFLICTS+=		opera-acroread5-[0-9]*
CONFLICTS+=		opera-acroread7-[0-9]*

ACROREAD=		Acrobat4
ACRO_SUBDIR=		Browsers

.include "../../www/opera-acroread/Makefile.common"
