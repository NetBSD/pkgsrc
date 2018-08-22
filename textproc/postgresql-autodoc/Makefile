# $NetBSD: Makefile,v 1.32 2018/08/22 09:47:12 wiz Exp $
#

DISTNAME=	postgresql_autodoc-1.30
PKGREVISION=	7
CATEGORIES=	textproc databases
#MASTER_SITES=	http://www.rbt.ca/autodoc/binaries/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.rbt.ca/autodoc/
COMMENT=	Generate HTML, DOT, and XML description of database structure

DEPENDS+=	p5-Term-ReadKey-[0-9]*:../../devel/p5-Term-ReadKey
DEPENDS+=	p5-DBD-postgresql-[0-9]*:../../databases/p5-DBD-postgresql
DEPENDS+=	p5-HTML-Template-[0-9]*:../../www/p5-HTML-Template

WRKSRC=		${WRKDIR}/postgresql_autodoc
USE_TOOLS+=	gmake perl:run
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--datadir=${PREFIX:Q}/share
CONFIGURE_ENV+=	ac_cv_path_PERL=${PERL5:Q}

INSTALL_MAKE_FLAGS=	prefix=${DESTDIR}${PREFIX} \
			datadir=${DESTDIR}${PREFIX}/share/postgresql_autodoc

.include "../../mk/bsd.pkg.mk"
