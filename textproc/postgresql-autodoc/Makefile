# $NetBSD: Makefile,v 1.9 2004/01/20 12:26:50 agc Exp $
#

DISTNAME=	postgresql_autodoc-1.12
CATEGORIES=	textproc databases
MASTER_SITES=	http://www.rbt.ca/autodoc/binaries/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.rbt.ca/autodoc/
COMMENT=	Generate HTML, DOT, and XML description of database structure

DEPENDS=	p5-DBD-postgresql-[0-9]*:../../databases/p5-DBD-postgresql
DEPENDS+=	p5-HTML-Template-[0-9]*:../../www/p5-HTML-Template

WRKSRC=		${WRKDIR}/postgresql_autodoc
USE_PERL5=	yes
USE_GMAKE=	yes
USE_BUILDLINK2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${PREFIX}/share/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
