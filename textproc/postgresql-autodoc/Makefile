# $NetBSD: Makefile,v 1.2 2002/09/06 00:24:56 mjl Exp $
#

VERS=		1.00
DISTNAME=	postgresql_autodoc-${VERS}
CATEGORIES=	textproc database
MASTER_SITES=	http://www.rbt.ca/autodoc/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.rbt.ca/autodoc/
COMMENT=	Generate HTML, DOT, and XML description of database structure

DEPENDS+=	p5-DBI-[0-9]*:../../databases/p5-DBI
DEPENDS+=	p5-DBD-postgresql-[0-9]*:../../databases/p5-DBD-postgresql

#NO_CONFIGURE=	YES	# Configure needed for REPLACE_PERL
NO_BUILD=	YES
REPLACE_PERL=	postgresql_autodoc.pl

WRKSRC=         ${WRKDIR}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/postgresql_autodoc.pl ${PREFIX}/bin/postgresql_autodoc

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
