# $NetBSD: Makefile,v 1.30 2012/10/25 06:57:09 asau Exp $

DISTNAME=	yodl-1.31.18
PKGREVISION=	9
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.lilypond.org/pub/yodl/development/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.xs4all.nl/~jantien/yodl/
COMMENT=	High-level document preparation system

GNU_CONFIGURE=	YES
USE_TOOLS+=	bison flex gmake
MAKE_FILE=	GNUmakefile
CONFIGURE_ENV+=	ILDFLAGS=${LDFLAGS:Q}

SUBST_CLASSES+=		python
SUBST_FILES.python=	scripts/yodl2texinfo-post.py
SUBST_SED.python+=	-e 's,@PYTHON@,${PYTHONBIN},g'
SUBST_STAGE.python=	pre-configure

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}
INSTALL_MAKE_FLAGS+=	infodir=${DESTDIR}${PREFIX}/${PKGINFODIR}
INSTALL_MAKE_FLAGS+=	mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

.include "../../lang/python/application.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
