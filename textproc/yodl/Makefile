# $NetBSD: Makefile,v 1.23 2006/09/09 02:46:09 obache Exp $

DISTNAME=	yodl-1.31.18
PKGREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.lilypond.org/pub/yodl/development/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.xs4all.nl/~jantien/yodl/
COMMENT=	High-level document preparation system

GNU_CONFIGURE=	YES
USE_TOOLS+=	bison flex gmake
MAKE_FILE=	GNUmakefile
CONFIGURE_ENV+=	ILDFLAGS=${LDFLAGS:Q}

.include "../../lang/python/application.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
