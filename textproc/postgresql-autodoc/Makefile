# $NetBSD: Makefile,v 1.16 2005/05/22 20:08:35 jlam Exp $
#

DISTNAME=	postgresql_autodoc-1.24
# PKGREVISION=	1
CATEGORIES=	textproc databases
MASTER_SITES=	http://www.rbt.ca/autodoc/binaries/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.rbt.ca/autodoc/
COMMENT=	Generate HTML, DOT, and XML description of database structure

DEPENDS=	p5-DBD-postgresql-[0-9]*:../../databases/p5-DBD-postgresql
DEPENDS+=	p5-HTML-Template-[0-9]*:../../www/p5-HTML-Template

WRKSRC=		${WRKDIR}/postgresql_autodoc
USE_PERL5=	yes
USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${PREFIX}/share/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
