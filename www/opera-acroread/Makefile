# $NetBSD: Makefile,v 1.8 2007/07/29 05:20:00 jlam Exp $

DISTNAME=		opera-acroread-1.0
PKGREVISION=		4

MAINTAINER=		jschauma@NetBSD.org
COMMENT=		Acrobat Reader 4 plugin for opera

DEPENDS+=		acroread-4.[0-9]*:../../print/acroread
CONFLICTS+=		opera-acroread3-[0-9]*
CONFLICTS+=		opera-acroread5-[0-9]*
CONFLICTS+=		opera-acroread7-[0-9]*

ACROREAD=		Acrobat4
ACRO_SUBDIR=		Browsers

.include "../../www/opera-acroread/Makefile.common"
.include "../../mk/bsd.pkg.mk"
