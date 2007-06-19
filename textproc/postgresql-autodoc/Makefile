# $NetBSD: Makefile,v 1.21 2007/06/19 18:46:15 mjl Exp $
#

DISTNAME=	postgresql_autodoc-1.30
#PKGREVISION=	2
CATEGORIES=	textproc databases
MASTER_SITES=	http://www.rbt.ca/autodoc/binaries/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.rbt.ca/autodoc/
COMMENT=	Generate HTML, DOT, and XML description of database structure

DEPENDS+=	p5-DBD-postgresql-[0-9]*:../../databases/p5-DBD-postgresql
DEPENDS+=	p5-HTML-Template-[0-9]*:../../www/p5-HTML-Template

WRKSRC=		${WRKDIR}/postgresql_autodoc
USE_TOOLS+=	gmake perl:run
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--datadir=${PREFIX:Q}/share
CONFIGURE_ENV+=	ac_cv_path_PERL=${PERL5:Q}

.include "../../mk/bsd.pkg.mk"
