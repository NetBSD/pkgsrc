# $NetBSD: Makefile,v 1.12 2026/10/21 10:01:19 sborrill Exp $

DISTNAME=		texi2roff-2.0
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_TEX_CTAN:=support/texi2roff/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://texinfo.org/texi2roff/
COMMENT=		Texinfo-to-ROFF direct translator

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

BUILD_TARGET=
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/texi2roff ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/texi2roff.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
