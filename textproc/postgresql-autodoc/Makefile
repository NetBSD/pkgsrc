# $NetBSD: Makefile,v 1.1.1.1 2002/08/31 02:56:42 mjl Exp $
#

DISTNAME=	postgresql_autodoc_0.99
PKGNAME=	postgresql-autodoc-0.99
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
