# $NetBSD: Makefile,v 1.18 2005/07/16 01:19:24 jlam Exp $
#

DISTNAME=	postgresql_autodoc-1.24
PKGREVISION=	1
CATEGORIES=	textproc databases
MASTER_SITES=	http://www.rbt.ca/autodoc/binaries/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.rbt.ca/autodoc/
COMMENT=	Generate HTML, DOT, and XML description of database structure

DEPENDS=	p5-DBD-postgresql-[0-9]*:../../databases/p5-DBD-postgresql
DEPENDS+=	p5-HTML-Template-[0-9]*:../../www/p5-HTML-Template

WRKSRC=		${WRKDIR}/postgresql_autodoc
USE_TOOLS+=	gmake perl:run
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${PREFIX}/share/${PKGBASE}
CONFIGURE_ENV+=	ac_cv_path_PERL=${PERL5}

.include "../../mk/bsd.pkg.mk"
