# $NetBSD: Makefile,v 1.5 2003/04/25 20:20:35 jmmv Exp $
#

VERS=		1.01
DISTNAME=	postgresql_autodoc-${VERS}
WRKSRC=         ${WRKDIR}
CATEGORIES=	textproc databases
MASTER_SITES=	http://www.rbt.ca/autodoc/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.rbt.ca/autodoc/
COMMENT=	Generate HTML, DOT, and XML description of database structure

DEPENDS+=	p5-DBI-[0-9]*:../../databases/p5-DBI
DEPENDS+=	p5-DBD-postgresql-[0-9]*:../../databases/p5-DBD-postgresql

#NO_CONFIGURE=	YES	# Configure needed for REPLACE_PERL
NO_BUILD=	YES
REPLACE_PERL=	postgresql_autodoc.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/postgresql_autodoc.pl ${PREFIX}/bin/postgresql_autodoc

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
