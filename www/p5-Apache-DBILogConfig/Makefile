# $NetBSD: Makefile,v 1.1.1.1 2001/04/27 20:38:48 wiz Exp $
#

DISTNAME=	Apache-DBILogConfig-0.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	packages@NetBSD.org
COMMENT=	A database-independent Apache database logger

DEPENDS+=	ap-DBI-*:../../www/ap-DBI
DEPENDS+=	p5-TimeDate-*:../../devel/p5-TimeDate

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Apache/DBILogConfig/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
